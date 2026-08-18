/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:42:38 by ywada             #+#    #+#             */
/*   Updated: 2024/11/09 18:20:59 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	div;
	long	nbl;

	nbl = n;
	if (nbl < 0)
	{
		write(fd, "-", 1);
		nbl = -nbl;
	}
	div = 1;
	while (nbl / (div * 10) != 0)
	{
		div *= 10;
	}
	while (div != 0)
	{
		c = '0' + nbl / div % 10;
		write(fd, &c, 1);
		div /= 10;
	}
}

// int	main(void)
// {
// 	ft_putnbr_fd(42, 1);
// 	ft_putnbr_fd(-42, 1);
// 	ft_putnbr_fd(0, 1);
// 	ft_putnbr_fd(10, 1);
// 	ft_putnbr_fd(2147483647, 1);
// 	ft_putnbr_fd(-2147483648, 1);
// 	return (0);
// }
