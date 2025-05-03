
#include "variable.h"
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_getvar(t_var *var, const char *name)
{
	size_t	len1;
	size_t	len2;

	if (var == NULL || name == NULL)
		return (NULL);
	while (var != NULL)
	{
		len1 = ft_strlen(var->name);
		len2 = ft_strlen(name);
		if (len1 == len2 && ft_strncmp(var->name, name, ft_strlen(name)) == 0)
			return (var->value);
		var = var->next;
	}
	return (NULL);
}

t_var	*ft_getvar_ptr(t_var *var, const char *name)
{
	size_t	len1;
	size_t	len2;

	if (var == NULL || name == NULL)
		return (NULL);
	while (var != NULL)
	{
		len1 = ft_strlen(var->name);
		len2 = ft_strlen(name);
		if (len1 == len2 && ft_strncmp(var->name, name, ft_strlen(name)) == 0)
			return (var);
		var = var->next;
	}
	return (NULL);
}

int	ft_setvar(t_var *var, const char *name, const char *val)
{
	t_var	*var_to_add;

	if (ft_getvar(var, name) == NULL)
	{
		var_to_add = new_var();
		if (var_to_add == NULL)
			return (-1);
		get_var_last(var)->next = var_to_add;
		var_to_add->name = ft_strdup(name);
		var_to_add->value = ft_strdup(val);
		if (var_to_add->name == NULL || var_to_add->value == NULL)
			return (free_var(var_to_add), -1);
		var_to_add->is_env = 0;
	}
	else
	{
		var_to_add = ft_getvar_ptr(var, name);
		free(var_to_add->value);
		var_to_add->value = ft_strdup(val);
		if (var_to_add->value == NULL)
			return (-1);
	}
	return (0);
}

static int	fill_envp(char **envp, t_var *var)
{
	size_t	i;
	size_t	name_len;
	size_t	val_len;

	i = 0;
	while (var != NULL)
	{
		if (var->is_env)
		{
			name_len = ft_strlen(var->name);
			val_len = ft_strlen(var->value);
			envp[i] = malloc(sizeof(char) * (name_len + val_len + 2));
			if (envp[i] == NULL)
				return (ft_free_strs(envp), -1);
			ft_strlcpy(envp[i], var->name, name_len + 1);
			envp[i][name_len] = '=';
			ft_strlcpy(envp[i] + name_len + 1, var->value, val_len + 1);
			envp[i][name_len + 1 + val_len] = '\0';
			i++;
		}
		var = var->next;
	}
	return (0);
}

char	**get_env_arr(t_var *var)
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
	return (envp);
}
