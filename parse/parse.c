
#include "parse.h"
#include "../minishell.h"
#include <libft.h>

t_cmd	*kantan_parse(t_var *var, char *line)
{
	t_cmd	*head = NULL;
	t_cmd	*current = NULL;
	char	**pipe_split;
	char	**space_split;
	int		i;

	(void)var;
	// Split the line by '|'
	pipe_split = ft_split(line, '|');
	if (!pipe_split)
		return (NULL);

	// Iterate over each pipe-separated segment
	for (i = 0; pipe_split[i]; i++)
	{
		// Allocate a new command node
		t_cmd *shin_cmd = new_cmd();
		if (!shin_cmd)
			return (NULL); // Handle allocation failure

		// Split the segment by spaces
		space_split = ft_split(pipe_split[i], ' ');
		if (!space_split)
			return (NULL);

		// Assign arguments to the command node
		shin_cmd->args = space_split;
		shin_cmd->cmd = space_split[0];
		shin_cmd->argc = ft_count_strs(space_split);

		// Append to the linked list
		if (!head)
			head = shin_cmd;
		else
			current->next = shin_cmd;
		current = shin_cmd;
	}

	// Free the pipe_split array
	ft_free_strs(pipe_split);

	return (head);
}

t_cmd	*parse(t_var *var, char *line)
{
	return (kantan_parse(var, line));
}

