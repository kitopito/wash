
#include <stdlib.h>

static size_t	count_string(const char *str, char c)
{
	size_t	i;
	size_t	string_num;

	i = 0;
	string_num = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			string_num++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else
		{
			i++;
		}
	}
	return (string_num);
}

static char	*copy_str(const char *str, char c)
{
	size_t	i;
	size_t	length;
	char	*copy;

	length = 0;
	while (str[length] != '\0' && str[length] != c)
	{
		length++;
	}
	copy = malloc(sizeof(char) * (length + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	free_str_ary(char **str_ary)
{
	size_t	i;

	i = 0;
	while (str_ary[i] != NULL)
	{
		free(str_ary[i]);
		i++;
	}
	free(str_ary);
}

static char	**fill_split_array(const char *str, char **str_ary, char c)
{
	size_t	i;
	size_t	str_index;

	i = 0;
	str_index = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			str_ary[str_index] = copy_str(str + i, c);
			if (str_ary[str_index] == NULL)
			{
				free_str_ary(str_ary);
				return (NULL);
			}
			str_index++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else
			i++;
	}
	str_ary[str_index] = NULL;
	return (str_ary);
}

char	**ft_split(char const *s, char c)
{
	char	**str_ary;

	if (s == NULL)
		return (NULL);
	str_ary = malloc(sizeof(char *) * (count_string(s, c) + 1));
	if (str_ary == NULL)
		return (NULL);
	if (fill_split_array(s, str_ary, c) == NULL)
		return (NULL);
	return (str_ary);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	char	**split_str;
// 	size_t	i;

// 	str = "Hello, World! ,,,  hoge , ";
// 	split_str = ft_split(str, ',');
// 	for (i = 0; split_str[i]; i++)
// 	{
// 		printf("%s\n", split_str[i]);
// 		free(split_str[i]);
// 	}
// 	free(split_str);
// 	str = "Hello, World! ,,,  hoge , ";
// 	split_str = ft_split(str, '\0');
// 	for (i = 0; split_str[i]; i++)
// 	{
// 		printf("%s\n", split_str[i]);
// 		free(split_str[i]);
// 	}
// 	free(split_str);
// 	str = "";
// 	split_str = ft_split(str, '\0');
// 	for (i = 0; split_str[i]; i++)
// 	{
// 		printf("%s\n", split_str[i]);
// 		free(split_str[i]);
// 	}
// 	free(split_str);
// 	return (0);
// }
