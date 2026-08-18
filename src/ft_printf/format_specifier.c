/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:06:04 by ywada             #+#    #+#             */
/*   Updated: 2025/02/18 17:39:52 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_specifier.h"
#include "limits.h"

void	reset_format(t_format_spec *format, int fd)
{
	format->fd = fd;
	format->flag_space = 0;
	format->flag_plus = 0;
	format->flag_minus = 0;
	format->flag_zero = 0;
	format->flag_hash = 0;
	format->flag_precision = 0;
	format->width = 0;
	format->precision = INT_MAX;
	format->type = '\0';
	format->padding = '\0';
	return ;
}
