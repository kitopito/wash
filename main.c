
#include "exe_cmd/exe_cmd.h"
#include "minishell.h"
#include "parse/parse.h"
#include "signal/shell_signal.h"
#include "variable/variable.h"
#include <libft.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

//#define MAX_HISTORY_NO 5

#define PROMPT "minishell$ "

static void	process_command(t_shell *sh)
{
	int		status;
	char	*status_str;

	sh->current_cmd = parse(sh->var, sh->line);
	status = exe_cmd(sh->current_cmd, sh);
	ft_free_cmd(sh->current_cmd);
	sh->current_cmd = NULL;
	status_str = ft_itoa(status);
	if (status_str == NULL)
	{
		perror("malloc");
		destroy_shell(sh);
		exit(1);
	}
	ft_setvar(sh->var, "?", status_str);
	free(status_str);
}

int	main(void)
{
	t_shell	*sh;
	int		status;

	sh = init_shell();
	shell_signal_init(sh);
	sh->line = readline(PROMPT);
	while (sh->line != NULL)
	{
		if (sh->line[0] != '\0')
		{
			process_command(sh);
			add_history(sh->line);
		}
		set_sig_status(sh);
		shell_signal_init(sh);
		free(sh->line);
		sh->line = readline(PROMPT);
	}
	printf("exit\n");
	status = ft_atoi(ft_getvar(sh->var, "?"));
	destroy_shell(sh);
	return (status);
}
