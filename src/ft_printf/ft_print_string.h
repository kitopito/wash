/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:19:43 by ywada             #+#    #+#             */
/*   Updated: 2024/11/20 09:25:44 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_STRING_H
# define FT_PRINT_STRING_H

# include "format_specifier.h"
# include "libft/libft.h"
# include <stddef.h>
# include <unistd.h>

int	ft_print_char(t_format_spec *spec, char c);

int	ft_print_str(t_format_spec *format, char *str);

#endif
