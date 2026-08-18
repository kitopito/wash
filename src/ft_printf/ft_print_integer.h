/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:22:16 by ywada             #+#    #+#             */
/*   Updated: 2024/11/23 23:13:27 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_INTEGER_H
# define FT_PRINT_INTEGER_H

# include "format_specifier.h"

int	ft_put_int(t_format_spec *spec, char *str, int digit_num, char sign);

int	ft_print_int(t_format_spec *spec, va_list ap);

int	ft_print_uint(t_format_spec *spec, va_list ap);

int	ft_put_hex(t_format_spec *spec, char *str, int digit_num, unsigned int val);

int	ft_print_hex(t_format_spec *spec, va_list ap);

#endif
