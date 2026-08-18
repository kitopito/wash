
#include "../minishell.h"
#include "shell_signal.h"
#include <readline/readline.h>
#include <signal.h>
#include <stdlib.h>

static volatile sig_atomic_t	g_shell_signal;

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGINT)
		g_shell_signal = signum;
}

int	shell_event_hook(void)
{
	static int	signum;

	if (g_shell_signal == SIGINT && g_shell_signal != signum)
	{
		rl_replace_line("", 0);
		rl_done = 1;
	}
	signum = g_shell_signal;
	return (0);
}

int	*get_g_sig(void)
{
	return ((int *)(&g_shell_signal));
}

void	cmd_exe_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	g_shell_signal = signum;
	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_done = 1;
	}
	else if (signum == SIGQUIT)
	{
		write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
		rl_replace_line("", 0);
		rl_done = 1;
	}
}

void	set_sig_status(t_shell *sh)
{
	if (g_shell_signal == SIGINT)
	{
		ft_setvar(sh->var, "?", "130");
		g_shell_signal = 0;
	}
	if (g_shell_signal == SIGQUIT)
	{
		ft_setvar(sh->var, "?", "131");
		g_shell_signal = 0;
	}
}
