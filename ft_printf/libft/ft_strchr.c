/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:53:58 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 18:10:28 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str[] = "Hello, World!";
// 	char c = '\0';
// 	char *p;

// 	char str1[] = "Hello, World!";
// 	char *p1;

// 	p1 = ft_strchr(str, c);
// 	if (p1)
// 		printf("The first occurrence of %c is at position %ld.\n", c, p1 - str
// 			+ 1);
// 	else
// 		printf("%c is not found in the string.\n", c);

// 	p = strchr(str1, c);
// 	if (p)
// 		printf("The first occurrence of %c is at position %ld.\n", c, p - str1
// 			+ 1);
// 	else
// 		printf("%c is not found in the string.\n", c);

// 	return (0);
// }