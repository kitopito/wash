
#include "variable.h"
#include <libft.h>
#include <stdlib.h>

t_var	*new_var(void)
{
	t_var	*new_var;

	new_var = malloc(sizeof(t_var));
	if (new_var == NULL)
		return (NULL);
	new_var->name = NULL;
	new_var->value = NULL;
	new_var->next = NULL;
	new_var->is_env = 0;
	return (new_var);
}

void	free_var_list(t_var *head)
{
	t_var	*current;
	t_var	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->name);
		free(current->value);
		free(current);
		current = next;
	}
}

t_var	*get_var_last(t_var *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	free_var(t_var *var)
{
	free(var->name);
	free(var->value);
	free(var);
}

int	delete_var(t_var **var, const char *var_str)
{
	t_var	*prev;
	t_var	*current;

	prev = NULL;
	current = *var;
	while (current != NULL)
	{
		if (ft_strcmp(current->name, var_str) == 0)
		{
			if (prev == NULL)
				*var = current->next;
			else
				prev->next = current->next;
			free(current->name);
			free(current->value);
			free(current);
			return (0);
		}
		prev = current;
		current = current->next;
	}
	return (-1);
}
