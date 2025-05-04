/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:34:53 by ywada             #+#    #+#             */
/*   Updated: 2025/02/18 17:42:46 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_UTIL_H
# define FT_PRINT_UTIL_H

# include <stddef.h>

int		print_n_char(int fd, int n, char c);

void	init_str(char *str, size_t len);

size_t	ft_sprint_ulong(char *str, unsigned long value, char *base);

#endif
