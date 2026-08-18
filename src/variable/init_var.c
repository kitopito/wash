
#include "stdlib.h"
#include "variable.h"
#include <libft.h>

extern char		**environ;

static t_var	*parse_env(const char *env)
{
	t_var	*new_env;
	size_t	eq_index;

	if (env == NULL)
		return (NULL);
	if (ft_strchr(env, '=') == NULL)
		return (NULL);
	new_env = new_var();
	if (new_env == NULL)
		return (NULL);
	eq_index = ft_strchr(env, '=') - env;
	new_env->name = malloc(sizeof(char) * (eq_index + 1));
	new_env->value = ft_strdup(env + eq_index + 1);
	if (new_env->name == NULL || new_env->value == NULL)
	{
		free(new_env->name);
		free(new_env->value);
		free(new_env);
		return (NULL);
	}
	ft_strlcpy(new_env->name, env, eq_index + 1);
	new_env->is_env = 1;
	return (new_env);
}

t_var	*init_var(void)
{
	char	**env;
	t_var	*head;
	t_var	*last;

	head = NULL;
	env = environ;
	while (*env != NULL)
	{
		if (head == NULL)
		{
			head = parse_env(*env);
			last = head;
		}
		else
		{
			last->next = parse_env(*env);
			last = last->next;
		}
		if (last == NULL)
			free_var_list(head);
		if (last == NULL)
			return (NULL);
		env++;
	}
	return (head);
}
