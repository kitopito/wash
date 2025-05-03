
#include "../minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FT_PWD_ERR 1
#define FT_PWD_SUCCESS 0

int	ft_pwd(int argc, char **argv, t_shell *sh)
{
	char	*pwd;

	(void)argv;
	(void)argc;
	(void)sh;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		perror("mish: pwd");
		return (FT_PWD_ERR);
	}
	printf("%s\n", pwd);
	free(pwd);
	return (FT_PWD_SUCCESS);
}
