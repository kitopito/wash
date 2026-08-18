
#include "../minishell.h"
#include "builtins.h"
#include <libft.h>
#include <stdio.h>

#define FT_ECHO_ERR 1
#define FT_ECHO_SUCCESS 0

#define FT_ECHO_OPTIONS "n"
#define FT_ECHO_OPTIONS_MAX 1

int	ft_echo(int argc, char **argv, t_shell *sh)
{
	size_t	i;
	char	option[FT_ECHO_OPTIONS_MAX + 1];

	(void)sh;
	ft_bzero(option, FT_ECHO_OPTIONS_MAX + 1);
	i = ft_getopt(argc, argv, option, FT_ECHO_OPTIONS);
	while (i < (size_t)argc)
	{
		if (printf("%s", argv[i]) < 0)
			return (FT_ECHO_SUCCESS);
		i++;
		if (i != (size_t)argc)
			printf(" ");
	}
	if (ft_strchr(option, 'n') == NULL)
		printf("\n");
	return (FT_ECHO_SUCCESS);
}
