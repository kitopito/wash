/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:09:56 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 17:57:30 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
		p++;
	while (p >= s && *p != (char)c)
		p--;
	if (*p == (char)c)
		return (p);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "Hello, World!";
// 	char c = '\0';
// 	char *p;

// 	p = ft_strrchr(str, c);
// 	if (p)
// 		printf("The last occurrence of %c is at position %ld.\n", c, p - str
// 			+ 1);
// 	else
// 		printf("%c is not found in the string.\n", c);

// 	return (0);
// }