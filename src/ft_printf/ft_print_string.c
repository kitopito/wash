/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:19:43 by ywada             #+#    #+#             */
/*   Updated: 2025/02/18 17:47:54 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_string.h"
#include "ft_print_util.h"

int	ft_print_char(t_format_spec *spec, char c)
{
	int	output_count;

	if (spec->width == 0)
		spec->width = 1;
	output_count = spec->width;
	if (spec->flag_minus == 0)
		print_n_char(spec->fd, spec->width - 1, ' ');
	write(spec->fd, &c, 1);
	if (spec->flag_minus == 1)
		print_n_char(spec->fd, spec->width - 1, ' ');
	return (output_count);
}

int	ft_print_str(t_format_spec *format, char *str)
{
	int	str_len;

	if (str == NULL)
	{
		if (format->precision < 6)
			return (ft_print_str(format, ""));
		else
			return (ft_print_str(format, "(null)"));
	}
	str_len = (int)ft_strlen(str);
	if (format->precision < str_len)
		str_len = format->precision;
	if (format->width < str_len)
		format->width = str_len;
	if (format->flag_minus == 0)
		print_n_char(format->fd, format->width - str_len, ' ');
	write(format->fd, str, str_len);
	if (format->flag_minus == 1)
		print_n_char(format->fd, format->width - str_len, ' ');
	return (format->width);
}
