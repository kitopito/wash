#include "minishell.h"
#include <libft.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void	print_error(char **message)
{
	size_t	i;

	i = 0;
	while (message[i] != NULL)
	{
		ft_putstr_fd(message[i], STDERR_FILENO);
		i++;
	}
}

void	print_error_format(int mish, char *arg, char *msg)
{
	if (mish != 0)
		ft_putstr_fd("mish: ", STDERR_FILENO);
	if (arg != NULL)
		ft_putstr_fd(arg, STDERR_FILENO);
	if (msg != NULL)
		ft_putstr_fd(msg, STDERR_FILENO);
}

void	ft_free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd->next;
		ft_free_strs(cmd->args);
		if (cmd->heredoc_delim)
			free(cmd->heredoc_delim);
		free(cmd->heredoc_buf);
		free(cmd);
		cmd = tmp;
	}
}

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->cmd = NULL;
	cmd->argc = 0;
	cmd->args = NULL;
	cmd->input_fd = -1;
	cmd->output_fd = -1;
	cmd->append = 0;
	cmd->heredoc_delim = NULL;
	cmd->heredoc_buf = NULL;
	cmd->pid = 0;
	cmd->next = NULL;
	return (cmd);
}

int	is_directory(const char *path)
{
	struct stat	stat_buf;

	if (stat(path, &stat_buf) == -1)
	{
		perror("stat");
		return (0);
	}
	if (S_ISDIR(stat_buf.st_mode))
		return (1);
	return (0);
}
