
#include "../minishell.h"
#include <libft.h>
#include <stdio.h>

int	ft_dummy(int argc, char **argv, t_shell *sh)
{
	int	status;

	(void)sh;
	if (argc == 1)
		return (0);
	status = ft_atoi(argv[1]);
	return (status);
}
