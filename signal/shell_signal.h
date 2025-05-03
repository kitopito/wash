
#ifndef SHELL_SIGNAL_H
# define SHELL_SIGNAL_H

# include <signal.h>

void	signal_handler(int sig);
int		shell_signal_init(t_shell *sh);
int		shell_signal_cmd_exe(t_shell *sh);

void	set_sig_status(t_shell *sh);

void	handler(int signum, siginfo_t *info, void *context);

void	cmd_exe_handler(int a, siginfo_t *b, void *c);

int		shell_signal_dfl(t_shell *sh);

int		*get_g_sig(void);

int		shell_event_hook(void);

#endif
