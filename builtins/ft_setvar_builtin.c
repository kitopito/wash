
#include "../minishell.h"
#include <libft.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FT_SETVAR_ERR 1
#define FT_SETVAR_NOT_COMMAND 127
#define FT_SETVAR_SUCCESS 0

int	is_valid_identifier(const char *str)
{
	size_t	i;

	if (ft_isalpha(str[0]) == 0 && str[0] != '_')
		return (0);
	i = 0;
	while (str[i] != '=' && str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
		{
			if (str[i] == '+' && str[i + 1] == '=')
			{
				i++;
				continue ;
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_setvar_builtin_plus(char *arg, t_var *var, t_shell *sh)
{
	char	*eq_ptr;
	char	*val;
	char	*prev_val;
	int		status;

	eq_ptr = ft_strchr(arg, '=');
	*eq_ptr = '\0';
	*(eq_ptr - 1) = '\0';
	prev_val = ft_getvar(var, arg);
	val = ft_strjoin(prev_val, eq_ptr + 1);
	if (val == NULL)
	{
		perror("malloc");
		destroy_shell(sh);
		exit(FT_SETVAR_ERR);
	}
	status = 0;
	if (ft_setvar(var, arg, val) == -1)
	{
		status = FT_SETVAR_ERR;
	}
	free(val);
	return (status);
}

int	ft_setvar_builtin_1(char *arg, t_var *var, t_shell *sh)
{
	char	*eq_ptr;
	char	*str[2];
	int		status;

	eq_ptr = ft_strchr(arg, '=');
	if (*(eq_ptr - 1) == '+')
		return (ft_setvar_builtin_plus(arg, var, sh));
	*eq_ptr = '\0';
	str[0] = ft_strdup(arg);
	str[1] = ft_strdup(eq_ptr + 1);
	if (str[0] == NULL || str[1] == NULL)
	{
		free(str[0]);
		free(str[1]);
		destroy_shell(sh);
		exit(FT_SETVAR_ERR);
	}
	status = 0;
	if (ft_setvar(var, str[0], str[1]) == -1)
	{
		status = FT_SETVAR_ERR;
	}
	free(str[0]);
	free(str[1]);
	return (status);
}

int	ft_setvar_builtin(int argc, char **argv, t_shell *sh)
{
	size_t	i;

	i = 0;
	while (i < (size_t)argc)
	{
		if (is_valid_identifier(argv[i]) == 0 || ft_strchr(argv[i],
				'=') == NULL)
		{
			write(STDERR_FILENO, argv[i], ft_strlen(argv[i]));
			write(STDERR_FILENO, ": command not found\n", 20);
			return (FT_SETVAR_NOT_COMMAND);
		}
		ft_setvar_builtin_1(argv[i], sh->var, sh);
		i++;
	}
	return (0);
}
