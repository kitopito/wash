
#include "libft.h"
#include <stddef.h>
#include <unistd.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	len;
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	len = ft_strlen((char *)s);
	i = 0;
	while (i < len)
	{
		f(i, s + i);
		i++;
	}
}

// #include <stdio.h>

// void	ft_toupper_i(unsigned int i, char *c)
// {
// 	if (i % 2 != 0)
// 		*c = ft_toupper(*c);
// }

// int	main(void)
// {
// 	char	s[20] = "hello World!";

// 	ft_striteri(s, ft_toupper_i);
// 	printf("%s\n", s);
// 	return (0);
// }
