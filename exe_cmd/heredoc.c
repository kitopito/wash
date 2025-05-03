
#include "../builtins/builtins.h"
#include "../minishell.h"
#include "../signal/shell_signal.h"
#include "exe_cmd.h"
#include <libft.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static int	heredoc_append_line(t_cmd *cmd, char *line, t_shell *sh)
{
	char	*tmp;
	char	*strs[4];

	tmp = line;
	line = parse_heredoc(line, sh->var);
	free(tmp);
	if (line == NULL)
		return (-1);
	strs[0] = cmd->heredoc_buf;
	strs[1] = line;
	strs[2] = "\n";
	strs[3] = NULL;
	tmp = cmd->heredoc_buf;
	cmd->heredoc_buf = ft_strconcat(strs);
	if (cmd->heredoc_buf == NULL)
	{
		free(tmp);
		free(line);
		return (-1);
	}
	free(tmp);
	free(line);
	return (0);
}

static void	write_heredoc(t_cmd *cmd)
{
	if (cmd->heredoc_buf != NULL)
		write(cmd->heredoc_pipe[1], cmd->heredoc_buf,
			ft_strlen(cmd->heredoc_buf));
	close(cmd->heredoc_pipe[1]);
	free(cmd->heredoc_buf);
	cmd->heredoc_buf = NULL;
}

static int	heredoc_readline(t_cmd *cmd, t_shell *sh)
{
	char	*line;

	line = readline("> ");
	while (line != NULL && ft_strcmp(line, cmd->heredoc_delim) != 0)
	{
		if (*get_g_sig() == SIGINT)
			return (free(line), -1);
		if (heredoc_append_line(cmd, line, sh) == -1)
		{
			destroy_shell(sh);
			exit(1);
		}
		line = readline("> ");
	}
	if (line == NULL)
	{
		ft_putstr_fd("mish: warning: here-document at", STDERR_FILENO);
		ft_putstr_fd("line delimited by end-of-file ", STDERR_FILENO);
		ft_putstr_fd("(wanted `", STDERR_FILENO);
		ft_putstr_fd(cmd->heredoc_delim, STDERR_FILENO);
		ft_putstr_fd("')\n", STDERR_FILENO);
	}
	free(line);
	return (0);
}

int	process_heredoc(t_cmd *cmd, t_shell *sh)
{
	while (cmd != NULL)
	{
		if (cmd->heredoc_delim != NULL)
		{
			cmd->heredoc_buf = ft_strdup("");
			if (pipe(cmd->heredoc_pipe) == -1 || cmd->heredoc_buf == NULL)
			{
				destroy_shell(sh);
				exit(1);
			}
			cmd->input_fd = cmd->heredoc_pipe[0];
			if (heredoc_readline(cmd, sh) == -1)
				return (-1);
			write_heredoc(cmd);
		}
		cmd = cmd->next;
	}
	return (0);
}
