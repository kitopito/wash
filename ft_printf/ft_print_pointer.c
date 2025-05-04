/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:32:23 by ywada             #+#    #+#             */
/*   Updated: 2025/02/18 17:47:44 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_specifier.h"
#include "ft_print_string.h"
#include "ft_print_util.h"
#include "libft/libft.h"
#include <stddef.h>
#include <unistd.h>

int	ft_print_pointer(t_format_spec *spec, va_list ap)
{
	unsigned long	pointer;
	char			print_str[18];
	int				digit_num;

	init_str(print_str, 18);
	pointer = (unsigned long)va_arg(ap, void *);
	digit_num = 0;
	if (pointer == 0)
	{
		spec->precision = 5;
		return (ft_print_str(spec, "(nil)"));
	}
	ft_strlcpy(print_str, "0x", 3);
	digit_num = ft_sprint_ulong(print_str + 2, pointer, "0123456789abcdef") + 2;
	if (spec->flag_minus == 0)
		print_n_char(spec->fd, spec->width - digit_num, ' ');
	write(spec->fd, print_str, digit_num);
	if (spec->flag_minus == 1)
		print_n_char(spec->fd, spec->width - digit_num, ' ');
	if (digit_num > spec->width)
		return (digit_num);
	return (spec->width);
}
