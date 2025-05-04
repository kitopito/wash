/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:47:36 by ywada             #+#    #+#             */
/*   Updated: 2025/02/18 17:39:15 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_SPECIFIER_H
# define FORMAT_SPECIFIER_H

# include <stdarg.h>

typedef struct s_format
{
	int		fd;

	int		flag_space;
	int		flag_plus;
	int		flag_minus;
	int		flag_zero;
	int		flag_hash;
	int		flag_precision;

	int		width;
	int		precision;
	char	type;
	char	padding;
}			t_format_spec;

void		reset_format(t_format_spec *format, int fd);

#endif