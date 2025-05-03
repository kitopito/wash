#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	ft_putchar_fd('H', 1);
// 	ft_putchar_fd('e', 1);
// 	ft_putchar_fd('l', 1);
// 	ft_putchar_fd('l', 1);
// 	ft_putchar_fd('o', 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putchar_fd('w', 2);
// 	ft_putchar_fd('o', 2);
// 	ft_putchar_fd('r', 2);
// 	ft_putchar_fd('l', 2);
// 	ft_putchar_fd('d', 2);
// 	return (0);
// }
