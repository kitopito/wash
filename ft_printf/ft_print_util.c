/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:34:53 by ywada             #+#    #+#             */
/*   Updated: 2025/02/18 17:42:16 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stddef.h>
#include <unistd.h>

int	print_n_char(int fd, int n, char c)
{
	char	chrs[10];
	int		i;
	int		output_count;

	if (n < 0)
		return (0);
	i = 0;
	while (i < 10)
	{
		chrs[i] = c;
		i++;
	}
	output_count = n;
	while (n > 10)
	{
		write(fd, chrs, 10);
		n -= 10;
	}
	write(fd, chrs, n);
	return (output_count);
}

void	init_str(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

size_t	ft_sprint_ulong(char *str, unsigned long value, char *base)
{
	size_t	radix;
	size_t	digit_num;
	size_t	digit_num_copy;
	long	value_copy;

	radix = ft_strlen(base);
	value_copy = value;
	if (value == 0)
	{
		str[0] = base[0];
		return (1);
	}
	digit_num = 0;
	while (value_copy != 0)
	{
		digit_num++;
		value_copy /= radix;
	}
	digit_num_copy = digit_num;
	while (digit_num_copy)
	{
		str[--digit_num_copy] = base[value % radix];
		value /= radix;
	}
	return (digit_num);
}
