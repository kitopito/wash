
#include "../builtins/builtins.h"
#include "../minishell.h"
#include "../signal/shell_signal.h"
#include "exe_cmd.h"
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int		wait_command(t_cmd *cmd_head);
void	exe_cmd_set_fd(t_cmd *cmd, int pipe_fd[2], t_shell *sh);
void	exe_cmd_fork(t_cmd *cmd, int pipe_fd[2], t_shell *sh);

int	exe_cmd(t_cmd *cmd, t_shell *sh)
{
	int		status;
	int		pipe_fd[2];
	t_cmd	*cmd_head;

	status = 0;
	if (process_heredoc(cmd, sh) == -1)
		return (0);
	shell_signal_cmd_exe(sh);
	cmd_head = cmd;
	pipe_fd[1] = -1;
	pipe_fd[0] = -1;
	while (cmd != NULL)
	{
		exe_cmd_set_fd(cmd, pipe_fd, sh);
		if (cmd->next == NULL && is_builin(cmd->cmd) == 1)
		{
			cmd->status = exe_cmd_solo(sh, cmd, cmd->input_fd, cmd->output_fd);
			return (cmd->status);
		}
		exe_cmd_fork(cmd, pipe_fd, sh);
		cmd = cmd->next;
	}
	status = wait_command(cmd_head);
	return (status);
}

void	exe_cmd_set_fd(t_cmd *cmd, int pipe_fd[2], t_shell *sh)
{
	if (cmd->next != NULL)
	{
		if (pipe(pipe_fd) < 0)
		{
			destroy_shell(sh);
			perror("pipe");
			exit(1);
		}
		if (cmd->next->input_fd == -1)
			cmd->next->input_fd = pipe_fd[0];
		else
			close(pipe_fd[0]);
		if (cmd->output_fd == -1 && cmd->next != NULL)
			cmd->output_fd = pipe_fd[1];
		else if (cmd->next != NULL)
			close(pipe_fd[1]);
	}
	if (cmd == sh->current_cmd && cmd->input_fd == -1)
		cmd->input_fd = STDIN_FILENO;
	if (cmd->next == NULL && cmd->output_fd == -1)
		cmd->output_fd = STDOUT_FILENO;
}

void	exe_cmd_fork(t_cmd *cmd, int pipe_fd[2], t_shell *sh)
{
	int	status;

	cmd->pid = fork();
	if (cmd->pid == 0)
	{
		if (cmd->next != NULL)
			close(pipe_fd[0]);
		status = exe_cmd_solo(sh, cmd, cmd->input_fd, cmd->output_fd);
		destroy_shell(sh);
		exit(status);
	}
	else
	{
		if (cmd->input_fd != STDIN_FILENO)
			close(cmd->input_fd);
		if (cmd->output_fd != STDOUT_FILENO)
			close(cmd->output_fd);
	}
}

int	wait_command(t_cmd *cmd_head)
{
	t_cmd	*cmd;
	int		status;

	cmd = cmd_head;
	while (cmd != NULL)
	{
		waitpid(cmd->pid, &cmd->status, 0);
		cmd = cmd->next;
	}
	cmd = cmd_head;
	while (cmd != NULL)
	{
		status = WEXITSTATUS(cmd->status);
		cmd = cmd->next;
	}
	return (status);
}
