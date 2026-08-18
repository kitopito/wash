
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
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
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	ft_putendl_fd("Hello, World!", 1);
// 	return (0);
// }
