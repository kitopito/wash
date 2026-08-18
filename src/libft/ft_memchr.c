
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return (p + i);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str[] = "Hello, World!";
// 	char c = 'o';
// 	char *p;

// 	p = ft_memchr(str, c, sizeof(str));
// 	printf("%s\n", p);
// 	char *pp = memchr(0, c, sizeof(str));
// 	printf("%s\n", pp);

// 	return (0);
// }