/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:03:43 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 14:28:29 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	char	*s_start;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start < s_len)
		s_start = (char *)s + start;
	else
		s_start = (char *)s + s_len;
	if (ft_strlen(s_start) < len)
		len = ft_strlen(s_start);
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s_start[i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	char	*sub;

// 	str = "Hello, World!";
// 	sub = ft_substr(str, 8, 9);
// 	printf("Substring: %s\n", sub);
// 	free(sub);
// 	return (0);
// }
