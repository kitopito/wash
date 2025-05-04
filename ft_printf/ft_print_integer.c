/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:22:16 by ywada             #+#    #+#             */
/*   Updated: 2025/02/18 17:52:31 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_specifier.h"
#include "ft_print_util.h"
#include "libft/libft.h"
#include <stddef.h>
#include <unistd.h>

int	ft_put_int(t_format_spec *spec, char *str, int digit_num, char sign)
{
	int	out_count;

	out_count = 0;
	if (spec->flag_minus == 0 && (spec->flag_zero == 0 || spec->flag_precision))
		out_count += print_n_char(spec->fd, spec->width, spec->padding);
	if (sign != '\0')
		out_count += write(spec->fd, &sign, 1);
	if (spec->flag_minus == 0 && (spec->flag_zero && spec->flag_precision == 0))
		out_count += print_n_char(spec->fd, spec->width, spec->padding);
	if (spec->flag_precision && spec->precision > digit_num)
		out_count += print_n_char(spec->fd, spec->precision - digit_num, '0');
	out_count += write(spec->fd, str, digit_num);
	if (spec->flag_minus == 1)
		out_count += print_n_char(spec->fd, spec->width, ' ');
	return (out_count);
}

int	ft_print_int(t_format_spec *spec, va_list ap)
{
	long	value;
	int		digit_num;
	char	print_str[11];
	char	sign;

	init_str(print_str, 11);
	value = (long)va_arg(ap, int);
	if (spec->flag_precision && spec->precision == 0 && value == 0)
		return (print_n_char(spec->fd, spec->width, ' '));
	sign = '\0';
	if (value < 0)
	{
		sign = '-';
		value = -value;
	}
	else if (spec->flag_plus == 1)
		sign = '+';
	else if (spec->flag_space == 1)
		sign = ' ';
	digit_num = ft_sprint_ulong(print_str, value, "0123456789");
	if (spec->precision < digit_num || !(spec->flag_precision))
		spec->precision = digit_num;
	spec->width -= spec->precision + (sign != '\0');
	return (ft_put_int(spec, print_str, digit_num, sign));
}

int	ft_print_uint(t_format_spec *spec, va_list ap)
{
	unsigned int	value;
	char			print_str[10];
	int				digit_num;

	init_str(print_str, 10);
	value = va_arg(ap, unsigned int);
	if (spec->flag_precision && spec->precision == 0 && value == 0)
		return (print_n_char(spec->fd, spec->width, ' '));
	digit_num = ft_sprint_ulong(print_str, value, "0123456789");
	if (spec->precision < digit_num || !(spec->flag_precision))
		spec->precision = digit_num;
	if (spec->flag_minus == 0)
		print_n_char(spec->fd, spec->width - spec->precision, spec->padding);
	if (spec->flag_precision && spec->precision > digit_num)
		print_n_char(spec->fd, spec->precision - digit_num, '0');
	write(spec->fd, print_str, digit_num);
	if (spec->flag_minus == 1)
		print_n_char(spec->fd, spec->width - spec->precision, ' ');
	if (spec->precision > spec->width)
		return (spec->precision);
	return (spec->width);
}

int	ft_put_hex(t_format_spec *spec, char *str, int digit_num, unsigned int val)
{
	int	out_count;

	out_count = 0;
	if (spec->flag_minus == 0 && spec->flag_zero == 0)
		out_count += print_n_char(spec->fd, spec->width, spec->padding);
	if (spec->flag_hash == 1 && val != 0)
	{
		if (spec->type == 'x')
			out_count += write(spec->fd, "0x", 2);
		else
			out_count += write(spec->fd, "0X", 2);
	}
	if (spec->flag_minus == 0 && spec->flag_zero)
		out_count += print_n_char(spec->fd, spec->width, spec->padding);
	if (spec->flag_precision && spec->precision > digit_num)
		out_count += print_n_char(spec->fd, spec->precision - digit_num, '0');
	out_count += write(spec->fd, str, digit_num);
	if (spec->flag_minus == 1)
		out_count += print_n_char(spec->fd, spec->width, ' ');
	return (out_count);
}

int	ft_print_hex(t_format_spec *spec, va_list ap)
{
	unsigned int	value;
	char			print_str[8];
	int				digit_num;

	init_str(print_str, 8);
	value = va_arg(ap, unsigned int);
	if (spec->flag_precision && spec->precision == 0 && value == 0)
		return (print_n_char(spec->fd, spec->width, ' '));
	if (spec->type == 'X')
		digit_num = ft_sprint_ulong(print_str, value, "0123456789ABCDEF");
	else
		digit_num = ft_sprint_ulong(print_str, value, "0123456789abcdef");
	if (spec->precision < digit_num || !(spec->flag_precision))
		spec->precision = digit_num;
	if (spec->flag_hash == 1 && value != 0)
		spec->width -= spec->precision + 2;
	else
		spec->width -= spec->precision;
	return (ft_put_hex(spec, print_str, digit_num, value));
}
