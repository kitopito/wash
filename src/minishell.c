
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

t_shell	*init_shell(void)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	if (shell == NULL)
	{
		perror("malloc");
		exit(1);
	}
	shell->line = NULL;
	shell->exit_status = 0;
	shell->current_cmd = NULL;
	shell->var = init_var();
	if (shell->var == NULL)
	{
		free(shell);
		exit(1);
	}
	ft_setvar(shell->var, "?", "0");
	return (shell);
}

void	destroy_shell(t_shell *sh)
{
	rl_clear_history();
	free(sh->line);
	free_var_list(sh->var);
	ft_free_cmd(sh->current_cmd);
	free(sh);
}
