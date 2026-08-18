/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:29:46 by ywada             #+#    #+#             */
/*   Updated: 2025/02/18 18:12:32 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
