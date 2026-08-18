
#include "../minishell.h"
#include "../variable/variable.h"
#include <stddef.h>
#include <unistd.h>

int	ft_unset(int argc, char **argv, t_shell *sh)
{
	size_t	i;

	if (argc == 1)
		return (0);
	i = 1;
	while (i < (size_t)argc)
	{
		delete_var(&(sh->var), argv[i]);
		i++;
	}
	return (0);
}
