
#include "../minishell.h"
#include "builtins.h"
#include <libft.h>
#include <stdio.h>

#define FT_EXPORT_ERR 1
#define FT_EXPORT_SUCCESS 0

int			export_with_no_args(t_shell *sh);
static int	is_valid_arg(char *arg);

int	ft_export(int argc, char **argv, t_shell *sh)
{
	t_var	*var;
	size_t	i;
	int		status;

	if (argc == 1)
		return (export_with_no_args(sh));
	status = FT_EXPORT_SUCCESS;
	i = 1;
	while (i < (size_t)argc)
	{
		if (is_valid_arg(argv[i]) == -1)
		{
			status = FT_EXPORT_ERR;
			i++;
			continue ;
		}
		if (ft_strchr(argv[i], '=') != NULL)
			if (ft_setvar_builtin_1(argv[i], sh->var, sh) != 0)
				return (FT_EXPORT_ERR);
		var = ft_getvar_ptr(sh->var, argv[i]);
		if (var != NULL)
			var->is_env = 1;
		i++;
	}
	return (status);
}

static int	is_valid_arg(char *arg)
{
	if (is_valid_identifier(arg) == 0)
	{
		ft_putstr_fd("mish: export: `", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		return (-1);
	}
	return (0);
}
