
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	result = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		result[i++] = *(s1++);
	while (*s2)
		result[i++] = *(s2++);
	result[len_s1 + len_s2] = '\0';
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	char	*result;

// 	s1 = "Hello";
// 	s2 = "World";
// 	result = ft_strjoin(s1, s2);
// 	printf("%s\n", result);
// 	free(result);
// 	//
// 	s1 = NULL;
// 	s2 = "!";
// 	result = ft_strjoin(s1, s2);
// 	printf("%s\n", result);
// 	free(result);
// 	//
// 	s1 = "Goodbye";
// 	s2 = NULL;
// 	result = ft_strjoin(s1, s2);
// 	printf("%s\n", result);
// 	free(result);
// 	//
// 	s1 = NULL;
// 	s2 = NULL;
// 	result = ft_strjoin(s1, s2);
// 	if (result != NULL)
// 		printf("%s\n", result);
// 	else
// 		printf("NULL\n");
// 	free(result);
// 	return (0);
// }

// gcc ft_strjoin.c ft_strdup.c ft_strlen.c
