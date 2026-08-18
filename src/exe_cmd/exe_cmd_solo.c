
#include "../builtins/builtins.h"
#include "../minishell.h"
#include "../signal/shell_signal.h"
#include "exe_cmd.h"
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static int	dup_close_io(int pipe_in, int pipe_out, t_cmd *cmd,
		int stdio_ark[2])
{
	if (pipe_in != STDIN_FILENO)
	{
		if (is_builin(cmd->cmd) && cmd->next == NULL)
			stdio_ark[0] = dup(STDIN_FILENO);
		if (dup2(pipe_in, STDIN_FILENO) < 0)
		{
			perror("dup");
			return (-1);
		}
		close(pipe_in);
	}
	if (pipe_out != STDOUT_FILENO)
	{
		if (is_builin(cmd->cmd) && cmd->next == NULL)
			stdio_ark[1] = dup(STDOUT_FILENO);
		if (dup2(pipe_out, STDOUT_FILENO) < 0)
		{
			perror("dup");
			return (-1);
		}
		close(pipe_out);
	}
	return (0);
}

static char	*get_cmd_path(t_cmd *cmd, t_shell *sh)
{
	char	*path;

	path = search_cmd_path(cmd->cmd, sh);
	if (path == NULL)
	{
		if (cmd->cmd[0] == '.' || ft_strchr(cmd->cmd, '/'))
			print_error_format(1, cmd->cmd, ": No such file or directory\n");
		else
			print_error_format(0, cmd->cmd, ": command not found\n");
		destroy_shell(sh);
		exit(127);
	}
	return (path);
}

static char	**cmd_get_env_arr(t_shell *sh, char *path)
{
	char	**envp;

	envp = get_env_arr(sh->var);
	if (envp == NULL)
	{
		perror("env");
		free(path);
		destroy_shell(sh);
		exit(1);
	}
	return (envp);
}

static void	cmd_failed(t_cmd *cmd, char **envp, char *path, t_shell *sh)
{
	ft_free_strs(envp);
	ft_putstr_fd("mish: ", STDERR_FILENO);
	ft_putstr_fd(cmd->cmd, STDERR_FILENO);
	if (is_directory(path) == 1)
		ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
	else if (access(path, X_OK) != 0)
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
	free(path);
	destroy_shell(sh);
	exit(126);
}

int	exe_cmd_solo(t_shell *sh, t_cmd *cmd, int pipe_in, int pipe_out)
{
	int		status;
	char	*path;
	char	**envp;
	int		stdio_ark[2];

	if (dup_close_io(pipe_in, pipe_out, cmd, stdio_ark) == -1)
		return (1);
	status = 0;
	if (is_builin(cmd->cmd))
	{
		status = exe_builtin(cmd, sh);
		if (pipe_in != STDIN_FILENO && cmd->next == NULL)
			dup2(stdio_ark[0], STDIN_FILENO);
		if (pipe_out != STDOUT_FILENO && cmd->next == NULL)
			dup2(stdio_ark[1], STDOUT_FILENO);
	}
	else
	{
		path = get_cmd_path(cmd, sh);
		envp = cmd_get_env_arr(sh, path);
		execve(path, cmd->args, envp);
		cmd_failed(cmd, envp, path, sh);
	}
	return (status);
}
