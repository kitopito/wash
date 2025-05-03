
#include "minishell.h"
#include <libft.h>
#include <stdlib.h>

char	**get_path_list(t_shell *sh)
{
	char	*path;
	char	**path_list;

	path = ft_getvar(sh->var, "PATH");
	if (path == NULL)
	{
		path_list = malloc(sizeof(char *));
		if (path_list == NULL)
		{
			return (NULL);
		}
		path_list[0] = NULL;
		return (path_list);
	}
	path_list = ft_split(path, ':');
	return (path_list);
}
