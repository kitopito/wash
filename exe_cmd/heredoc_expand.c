
#include "../builtins/builtins.h"
#include "../minishell.h"
#include "../signal/shell_signal.h"
#include "exe_cmd.h"
#include <libft.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static char	*heredoc_join_char(char *parse, char c)
{
	char	*tmp;
	char	str[2];

	str[1] = '\0';
	str[0] = c;
	tmp = parse;
	parse = ft_strjoin(parse, str);
	free(tmp);
	if (parse == NULL)
		return (NULL);
	return (parse);
}

static char	*heredoc_join_var(char *parse, char *line, t_var *var)
{
	char	*tmp;
	char	*var_name;
	char	*var_val;
	size_t	k;

	k = 0;
	while (ft_isalnum(line[k]) || line[k] == '_')
		k++;
	var_name = ft_substr(line, 0, k);
	var_val = ft_getvar(var, var_name);
	if (var_val == NULL)
		var_val = "";
	free(var_name);
	tmp = parse;
	parse = ft_strjoin(parse, var_val);
	free(tmp);
	if (parse == NULL)
		return (NULL);
	return (parse);
}

char	*parse_heredoc(char *line, t_var *var)
{
	size_t	i;
	char	*parse;

	parse = ft_strdup("");
	if (parse == NULL)
		return (NULL);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '$' && (ft_isalpha(line[i + 1]) || line[i + 1] == '_'))
		{
			i++;
			parse = heredoc_join_var(parse, line + i, var);
			while (ft_isalnum(line[i]) || line[i] == '_')
				i++;
		}
		else
		{
			parse = heredoc_join_char(parse, line[i]);
			i++;
		}
		if (parse == NULL)
			return (NULL);
	}
	return (parse);
}
