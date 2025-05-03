
#include "../minishell.h"
#include "builtins.h"
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

#define FT_EXPORT_ERR 1
#define FT_EXPORT_SUCCESS 0

static char	**get_env_val_arr(t_var *var);

int	export_with_no_args(t_shell *sh)
{
	char	**envs;
	size_t	i;

	envs = get_env_val_arr(sh->var);
	if (envs == NULL)
	{
		destroy_shell(sh);
		exit(FT_EXPORT_ERR);
	}
	i = 0;
	while (envs[i] != NULL)
	{
		printf("declare -x %s\n", envs[i]);
		i++;
	}
	ft_free_strs(envs);
	return (FT_EXPORT_SUCCESS);
}

static int	fill_envp(char **envp, t_var *var)
{
	size_t	i;
	char	*strs[5];

	strs[4] = NULL;
	i = 0;
	while (var != NULL)
	{
		if (var->is_env)
		{
			strs[0] = var->name;
			strs[1] = "=\"";
			strs[2] = var->value;
			strs[3] = "\"";
			envp[i] = ft_strconcat(strs);
			if (envp[i] == NULL)
			{
				ft_free_strs(envp);
				return (-1);
			}
			i++;
		}
		var = var->next;
	}
	return (0);
}

static void	sort_strs(char **strs)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	while (strs[i] != NULL)
	{
		j = i + 1;
		while (strs[j] != NULL)
		{
			if (ft_strcmp(strs[i], strs[j]) > 0)
			{
				tmp = strs[i];
				strs[i] = strs[j];
				strs[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static char	**get_env_val_arr(t_var *var)
{
	size_t	env_count;
	t_var	*var_cpy;
	char	**envp;

	var_cpy = var;
	env_count = 0;
	while (var_cpy != NULL)
	{
		if (var_cpy->is_env == 1)
			env_count++;
		var_cpy = var_cpy->next;
	}
	envp = ft_calloc(sizeof(char *), (env_count + 1));
	if (envp == NULL)
		return (NULL);
	if (fill_envp(envp, var) == -1)
		return (NULL);
	sort_strs(envp);
	return (envp);
}
