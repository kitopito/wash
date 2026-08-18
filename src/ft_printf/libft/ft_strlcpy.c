/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:14:34 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 13:23:34 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	dest[10];
// 	char	dest1[10];
// 	char	src[] = "Hello, World!";

// 	printf("%zu\n", ft_strlcpy(dest, src, 0));
// 	printf("%s\n", dest);
// 	printf("%zu\n", strlcpy(dest1, src, 0));
// 	printf("%s\n", dest1);
// 	return (0);
// }
