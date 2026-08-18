/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:32:23 by ywada             #+#    #+#             */
/*   Updated: 2024/11/20 09:33:35 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_POINTER_H
# define FT_PRINT_POINTER_H

# include "format_specifier.h"

int	ft_print_pointer(t_format_spec *spec, va_list ap);

#endif