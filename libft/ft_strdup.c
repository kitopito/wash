
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*cpy;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	cpy = malloc(sizeof(char) * (i + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	a[20] = "hoge fuga";

// 	printf("%s\n", a);
// 	printf("%s\n", ft_strdup(a));
// 	printf("%p\n", a);
// 	printf("%p\n", ft_strdup(a));
// }
