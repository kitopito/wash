/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:34:54 by ywada             #+#    #+#             */
/*   Updated: 2025/02/18 18:11:32 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vprintf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		output_count;

	va_start(ap, format);
	output_count = ft_vprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (output_count);
}

int	fd_printf(int fd, const char *format, ...)
{
	va_list	ap;
	int		output_count;

	va_start(ap, format);
	output_count = ft_vprintf(fd, format, ap);
	va_end(ap);
	return (output_count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// printf("% 4%d\n", 3);
// 	// printf("%04c\n", 'a');
// 	// printf("%-0c\n", 'a');
// 	// printf("%7s\n", "hoge");
// 	// printf("%3s\n", "hoge");
// 	// printf("%7s\n", NULL);
// 	// printf("pointer: %d\n", sizeof(void *));
// 	// printf("%p\n", "hoge");
// 	// printf("%6p\n", 0);
// 	// printf("%6p\n", 2);
// 	// printf("%3d\n", -23 % 10);
// 	// printf("%13x\n", -2);
// 	// printf("%x\n", 2147483649);
// 	// printf("%3%\n");
// 	// //	ft_printf("% 4%d\n", 3);
// 	// ft_printf("hoge%04c\n", 'a');
// 	// ft_printf("hoge%04c hoge: %c fuga\n", 'a', 'h');
// 	// ft_printf("hoge%04c hoge: % kuga\n", 'a', 'h');
// 	// ft_printf("%7s\n", "hoge");
// 	// ft_printf("%3s\n", "hoge");
// 	// ft_printf("%7s\n", NULL);
// 	// ft_printf("%p\n", "fuga");
// 	// ft_printf("%6p\n", 0);
// 	// ft_printf("%6p\n", 2);
// 	// ft_printf("%3d\n", 2);
// 	ft_printf("%3i\n", -2);
// 	ft_printf("%3d\n", 0);
// 	ft_printf("%3i\n", 10);
// 	ft_printf("%3d\n", 2147483647);
// 	ft_printf("%3d\n", -2147483648);
// 	// ft_printf("%3u\n", 2147483649);
// 	// ft_printf("%11u\n", 2147483649);
// 	// ft_printf("%13x\n", -2);
// 	// ft_printf("%x\n", 2147483649);
// 	// ft_printf("%3%\n");
// 	// ft_printf("%-0c\n", 'a');
// 	// // test
// 	// printf("%d\n", printf("%c", '0'));
// 	// printf("%d\n", ft_printf("%c", '0'));
// 	// printf("%d\n", printf("h %p %p ", INT_MIN, INT_MAX));
// 	// printf("%d\n", ft_printf("f %p %p ", INT_MIN, INT_MAX));
// 	// printf("%d\n", printf("h %10.2p ", 42));
// 	// printf("%d\n", printf("h %010.2p ", 42));
// 	// printf("%d\n", printf("h %10.2p ", 0));
// 	// printf("%d\n", printf("h %10.p ", 0));
// 	// printf("%d\n", printf("h %10.2s ", "hoge"));
// 	// printf("%d\n", printf("h %10.s ", "hoge"));
// 	// printf("%d\n", printf("h %10s ", 0));
// 	// printf("%d\n", printf("h %-10s ", 0));
// 	// printf("%d\n", printf("h %10.s ", 0));
// 	// printf("%d\n", printf("h %.5s ", 0));
// 	// printf("%d\n", printf("h %.6s ", 0));
// 	// printf("%d\n", printf("h %5.3d ", -42));
// 	// printf("%d\n", printf("h %5.3d ", 42));
// 	// printf("%d\n", printf("h %05.3d ", 42));
// 	// printf("%d\n", printf("h % 5.3d ", 42));
// 	// printf("%d\n", printf("h % 5.d ", 42));
// 	// printf("%d\n", printf("h % +5.3d ", 42));
// 	// printf("%d\n", printf("h % +-5.3d ", 42));
// 	// printf("%d\n", printf("h % +-5.d ", 0));
// 	// printf("%d\n", printf("h % +-5.0d ", 0));
// 	// printf("%d\n", printf("h % +-5.1d ", 0));
// 	// printf("%d\n", printf("h %5.d ", 1));
// 	// printf("%d\n", printf("h %5.1d ", 1));
// 	// printf("%d\n", printf("h %5.2d ", 1));
// 	// printf("%d\n", printf("h %- 5.3d ", -42));
// 	// printf("%d\n", printf("h %- 5.3d ", 42));
// 	// printf("%d\n", printf("h %05x ", 42));
// 	// printf("%d\n", printf("h %#05x ", 42));
// 	// printf("%d\n", printf("h %#05x ", 0));
// 	// printf("%d\n", printf("h %05x ", 0));
// 	// printf("%d\n", printf("h %5x ", 0));
// 	// printf("%d\n", printf("h %#p ", 0));
// 	// printf("%d\n", printf("h %#p ", 42));
// 	// printf("%d\n",
// 	// 	error test
// 	// printf("%d\n", printf("hoge%04c hoge: % kuga\n", 'a', 'h'));
// 	// printf("%d\n", ft_printf("hoge%04c hoge: % kuga\n", 'a', 'h'));
// 	// printf("%d\n", printf("hoge hoge: %12.5"));
// 	// printf("%d\n", ft_printf("hoge hoge: %12.5"));
// 	// printf("%d\n", printf("hoge hoge: %12.5 "));
// 	// printf("%d\n", ft_printf("hoge hoge: %12.5 "));
// 	// printf("%d\n", printf("hoge hoge: %12.5k"));
// 	// printf("%d\n", ft_printf("hoge hoge: %12.5k"));
// 	// printf("%d\n", printf("%"));
// 	// printf("%d\n", ft_printf("%"));
// 	// printf("%d\n", printf("% "));
// 	// printf("%d\n", ft_printf("% "));
// 	// printf("%d\n", printf("% k"));
// 	// printf("%d\n", ft_printf("% k"));
// 	// printf("%d\n", printf("% k"));
// 	// printf("%d\n", ft_printf("% k"));
// 	// printf("%d\n", printf("%  "));
// 	// printf("%d\n", ft_printf("%  "));
// 	// printf("%d\n", printf("%l"));
// 	// printf("%d\n", ft_printf("%l"));
// 	// printf("%d\n", printf("hoge %l %d", 42));
// 	// printf("%d\n", ft_printf("hoge %l %d", 42));
// 	// printf("%d\n", printf("hoge %42 %d", 42));
// 	// printf("%d\n", ft_printf("hoge %42 %d", 42));
// 	// printf("%d\n", printf("hoge %-# ."));
// 	// printf("%d\n", ft_printf("hoge %-# ."));
// 	// printf("%d\n", printf("hoge %-# 42"));
// 	// printf("%d\n", ft_printf("hoge %-# 42"));
// 	return (0);
// }