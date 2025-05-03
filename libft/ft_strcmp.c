
#include "libft.h"
#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	len;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l1 == l2 && ft_strncmp(s1, s2, l1) == 0)
		return (0);
	if (l1 > l2)
		len = l1;
	else
		len = l2;
	return (ft_strncmp(s1, s2, len));
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char s1[] = "Hello, World!";
// 	char s2[] = "Hello, Worle!";
// 	int result;

// 	result = ft_strcmp(s1, s2);
// 	printf("%d\n", result);
// 	result = strcmp(s1, s2);
// 	printf("%d\n", result);
// 	return (0);
// }