
#include "../minishell.h"
#include "shell_signal.h"
#include <readline/readline.h>
#include <signal.h>
#include <stdlib.h>

int	shell_signal_init(t_shell *sh)
{
	struct sigaction	si;

	sigemptyset(&si.sa_mask);
	si.sa_sigaction = handler;
	si.sa_flags = SA_SIGINFO;
	signal(SIGQUIT, SIG_IGN);
	if (sigaction(SIGINT, &si, NULL) < 0)
	{
		perror("sigaction");
		destroy_shell(sh);
		exit(1);
	}
	if (isatty(STDIN_FILENO))
		rl_event_hook = shell_event_hook;
	return (0);
}

int	shell_signal_cmd_exe(t_shell *sh)
{
	struct sigaction	si;
	struct sigaction	sq;

	sigemptyset(&si.sa_mask);
	si.sa_sigaction = cmd_exe_handler;
	si.sa_flags = SA_SIGINFO;
	sigemptyset(&sq.sa_mask);
	sq.sa_sigaction = cmd_exe_handler;
	sq.sa_flags = SA_SIGINFO;
	if (sigaction(SIGINT, &si, NULL) < 0 || sigaction(SIGQUIT, &sq, NULL) < 0)
	{
		perror("sigaction");
		destroy_shell(sh);
		exit(1);
	}
	signal(SIGPIPE, SIG_IGN);
	return (0);
}

int	shell_signal_dfl(t_shell *sh)
{
	(void)sh;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	return (0);
}
