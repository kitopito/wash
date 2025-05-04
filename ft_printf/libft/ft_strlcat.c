/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:05:27 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 17:30:04 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;

	if (size == 0)
		return (ft_strlen(src));
	dest_len = 0;
	i = 0;
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	while (src[i] != '\0' && i + dest_len < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	while (src[i] != '\0')
	{
		i++;
	}
	if (dest_len > size)
		return (size + i);
	return (dest_len + i);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	dest[10] = "Hello, ";
// 	char	dest1[10] = "Hello, ";
// 	char	src[] = "World!";
// 	size_t	size;

// 	size = sizeof(dest);
// 	// printf("%zu\n", ft_strlcat(dest, src, -1));
// 	// printf("%s\n", dest);
// 	// printf("%zu\n", strlcat(dest1, src, -1));
// 	// printf("%s\n", dest1);
// 	printf("%zu\n", ft_strlcat(dest, src, 0));
// 	printf("%s\n", dest);
// 	printf("%zu\n", strlcat(dest1, src, 0));
// 	printf("%s\n", dest1);
// 	return (0);
// }
