/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:50:44 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 12:03:24 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}

// #include <stdio.h>

// char	ft_toupper_i(unsigned int i, char c)
// {
// 	if (i % 2 != 0)
// 		return (ft_toupper(c));
// 	else
// 		return (c);
// }

// int	main(void)
// {
// 	char	*s;
// 	char	*result;

// 	s = "hello World!";
// 	result = ft_strmapi(s, &ft_toupper_i);
// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }
