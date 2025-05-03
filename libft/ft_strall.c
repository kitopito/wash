
#include <stddef.h>

int	ft_strall(const char *str, int (*condition)(int))
{
	if (str == NULL)
		return (0);
	if (str[0] == '\0')
		return (condition(str[0]));
	while (*str)
	{
		if (condition(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

// #include "libft.h"
// #include <stdio.h>

// int	main(void)
// {
// 	const char	*s1 = "";
// 	const char	*s2 = "aa11";
// 	const char	*s3 = "123ty";
// 	const char	*s4 = "345";
// 	const char	*s5 = "jfoww";

// 	printf("%s is digit: %d\n", s1, ft_strall(s1, ft_isdigit));
// 	printf("%s is digit: %d\n", s2, ft_strall(s2, ft_isdigit));
// 	printf("%s is digit: %d\n", s3, ft_strall(s3, ft_isdigit));
// 	printf("%s is digit: %d\n", s4, ft_strall(s4, ft_isdigit));
// 	printf("%s is digit: %d\n", s5, ft_strall(s5, ft_isdigit));
// 	printf("\n");
// 	printf("%s is alpha: %d\n", s1, ft_strall(s1, ft_isalpha));
// 	printf("%s is alpha: %d\n", s2, ft_strall(s2, ft_isalpha));
// 	printf("%s is alpha: %d\n", s3, ft_strall(s3, ft_isalpha));
// 	printf("%s is alpha: %d\n", s4, ft_strall(s4, ft_isalpha));
// 	printf("%s is alpha: %d\n", s5, ft_strall(s5, ft_isalpha));
// 	printf("\n");
// 	printf("%s is alnum: %d\n", s1, ft_strall(s1, ft_isalnum));
// 	printf("%s is alnum: %d\n", s2, ft_strall(s2, ft_isalnum));
// 	printf("%s is alnum: %d\n", s3, ft_strall(s3, ft_isalnum));
// 	printf("%s is alnum: %d\n", s4, ft_strall(s4, ft_isalnum));
// 	printf("%s is alnum: %d\n", s5, ft_strall(s5, ft_isalnum));
// }

// ccw ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_strall.c
