/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:52:34 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 18:00:34 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (big == NULL && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)(big));
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0' && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (0);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char str1[] = "Hello, World!";
// 	char str2[] = "o";
// 	char *p;

// 	p = strnstr(str1, str2, 5);
// 	printf("%s\n", p);
// 	p = ft_strnstr(str1, str2, 5);
// 	printf("%s\n", p);
// 	p = strnstr(NULL, str2, 0);
// 	printf("%s\n", p);
// 	p = ft_strnstr(NULL, str2, 0);
// 	printf("%s\n", p);
// 	// p = ft_strnstr(str1, NULL, 0);
// 	// printf("%s\n", p);
// 	// p = strnstr(str1, NULL, 0);
// 	// printf("%s\n", p);
// 	p = ft_strnstr("abbbcdefg", "bbc", 20);
// 	printf("%s\n", p);

// 	return (0);
// }