
#include "../minishell.h"
#include <stdio.h>
#include <unistd.h>

int	ft_env(int argc, char **argv, t_shell *sh)
{
	t_var	*var;

	(void)argv;
	if (argc > 1)
	{
		write(STDERR_FILENO, "env: too many arguments\n", 24);
		return (1);
	}
	var = sh->var;
	while (var != NULL)
	{
		if (var->is_env == 1)
			printf("%s=%s\n", var->name, var->value);
		var = var->next;
	}
	return (0);
}
