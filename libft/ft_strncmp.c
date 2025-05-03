
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (us1[i] != '\0' && us2[i] != '\0' && i < n)
	{
		if (us1[i] != us2[i])
		{
			return ((us1[i] - us2[i]));
		}
		i++;
	}
	if (i >= n)
	{
		return (0);
	}
	return ((us1[i] - us2[i]));
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s1[] = "Hello, World!";
// 	char	s2[] = "Hello, Worle!";
// 	int		result;
// 	int		cn;

// 	cn = 12;
// 	// s1[3] = -1;
// 	result = ft_strncmp(s1, s2, cn);
// 	printf("%d\n", result);
// 	result = strncmp(s1, s2, cn);
// 	printf("%d\n", result);
// 	return (0);
// }
