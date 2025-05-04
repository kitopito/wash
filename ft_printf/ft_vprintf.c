/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:09:04 by ywada             #+#    #+#             */
/*   Updated: 2025/02/18 18:34:17 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_specifier.h"
#include "ft_print_integer.h"
#include "ft_print_pointer.h"
#include "ft_print_string.h"
#include "libft/libft.h"
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

static int	ft_parse_format(const char **fmt_str, t_format_spec *spec);
static int	ft_print_format(const char *format, t_format_spec *spc, va_list ap);

int	ft_vprintf(int fd, const char *format, va_list ap)
{
	const char		*segment_start;
	int				output_count;
	t_format_spec	spec;

	output_count = 0;
	while (*format)
	{
		segment_start = format;
		while (*format && *format != '%')
			format++;
		if (format > segment_start)
			output_count += write(fd, segment_start, format - segment_start);
		if (*format == '%')
		{
			segment_start = ++format;
			reset_format(&spec, fd);
			if (ft_parse_format(&format, &spec) == 0)
				return (-1);
			output_count += ft_print_format(segment_start, &spec, ap);
			if (*format != '\0')
				format++;
		}
	}
	return (output_count);
}

static int	ft_parse_format(const char **fmt, t_format_spec *spec)
{
	while (**fmt != '\0' && ft_strchr("-+ #0", **fmt))
	{
		spec->flag_minus = spec->flag_minus | (**fmt == '-');
		spec->flag_plus = spec->flag_plus | (**fmt == '+');
		spec->flag_space = spec->flag_space | (**fmt == ' ');
		spec->flag_hash = spec->flag_hash | (**fmt == '#');
		spec->flag_zero = spec->flag_zero | (**fmt == '0');
		(*fmt)++;
	}
	spec->width = ft_atoi(*fmt);
	while (**fmt != '\0' && ft_isdigit(**fmt))
		(*fmt)++;
	if (**fmt == '.')
	{
		spec->precision = ft_atoi(++(*fmt));
		spec->flag_precision = 1;
	}
	while (**fmt != '\0' && ft_isdigit(**fmt))
		(*fmt)++;
	if (spec->flag_zero && spec->flag_minus == 0 && spec->flag_precision == 0)
		spec->padding = '0';
	else
		spec->padding = ' ';
	spec->type = **fmt;
	return (**fmt != '\0');
}

static int	ft_print_invalid_format(int fd, const char *fmt)
{
	int	i;

	i = 0;
	while (fmt[i] != '\0' && ft_strchr("-+ #0", fmt[i]))
		i++;
	while (fmt[i] != '\0' && ft_isdigit(fmt[i]))
		i++;
	if (fmt[i] == '.')
	{
		i++;
		while (fmt[i] != '\0' && ft_isdigit(fmt[i]))
			i++;
	}
	if (fmt[i] != '\0')
		i++;
	write(fd, "%", 1);
	write(fd, fmt, i);
	i++;
	return (i);
}

static int	ft_print_format(const char *fmt, t_format_spec *spec, va_list ap)
{
	if (spec->type == 'c')
		return (ft_print_char(spec, (char)va_arg(ap, int)));
	else if (spec->type == 's')
		return (ft_print_str(spec, va_arg(ap, char *)));
	else if (spec->type == 'p')
		return (ft_print_pointer(spec, ap));
	else if (spec->type == 'd' || spec->type == 'i')
		return (ft_print_int(spec, ap));
	else if (spec->type == 'u')
		return (ft_print_uint(spec, ap));
	else if (spec->type == 'x' || spec->type == 'X')
		return (ft_print_hex(spec, ap));
	else if (spec->type == '%')
	{
		write(spec->fd, "%", 1);
		return (1);
	}
	else
		return (ft_print_invalid_format(spec->fd, fmt));
}
