
#include "libft.h"
#include <stdlib.h>

static int	is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (s1 == 0 || set == 0)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_calloc(1, sizeof(char)));
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen((char *)s1) - 1;
	while (end >= start && is_in_set(s1[end], set))
		end--;
	len = end - start + 1;
	if (len <= 0)
		return (ft_calloc(1, sizeof(char)));
	trimmed = ft_substr(s1, start, len);
	return (trimmed);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s;
// 	char	*set;
// 	char	*trimmed;

// 	s = " ###		Hello, World!#  ##";
// 	set = " ##\t\n";
// 	trimmed = ft_strtrim(s, set);
// 	printf("%s\n", trimmed);
// 	free(trimmed);
// 	s = "##  ## \n 		## ";
// 	trimmed = ft_strtrim(s, set);
// 	printf("%s\n", trimmed);
// 	free(trimmed);
// 	return (0);
// }
