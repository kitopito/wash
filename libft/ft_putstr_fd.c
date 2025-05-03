
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	write(fd, s, i);
}

// int	main(void)
// {
// 	ft_putstr_fd("Hello, World!\n", 1);
// 	return (0);
// }
