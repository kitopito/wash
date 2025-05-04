/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:24:51 by ywada             #+#    #+#             */
/*   Updated: 2024/10/22 23:09:24 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*v1;
	unsigned char	*v2;

	v1 = (unsigned char *)s1;
	v2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (v1[i] != v2[i])
			return (v1[i] - v2[i]);
		i++;
	}
	if (i >= n)
		return (0);
	return (v1[i] - v2[i]);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str1[] = "Hello, Worlf!";
// 	char	str2[] = "Hello, World!";

// 	printf("%d\n", ft_memcmp(str1, str2, sizeof(str1))); // 0
// 	printf("%d\n", memcmp(str1, str2, sizeof(str1)));    // 0
// 	return (0);
// }
