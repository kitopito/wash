/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:24:41 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 18:50:11 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0' && is_space(str[i]) == 1)
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + sign * (str[i] - '0');
		i++;
	}
	return ((int)result);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	printf("%d\n", ft_atoi(" -1234ab567"));
// 	printf("%d\n", ft_atoi(" -0"));
// 	printf("%d\n", ft_atoi("1234"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r	1234"));
// 	printf("%d\n", ft_atoi(" \n\t  \0  \v\f\r	+1234"));
// 	printf("%d\n", ft_atoi(" \n\t  h  \v\f\r	1234"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r-1234"));
// 	printf("%d\n", ft_atoi("hoge \n\t\v\f\r-1234"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r-1234a4"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r-2147483648a4"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r-2147483649a4"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r-2147483647a4"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r-2147483648a4"));
// 	// atoi
// 	printf("=============================\n");
// 	// atoi
// 	printf("%d\n", atoi(" -1234ab567"));
// 	printf("%d\n", atoi(" -0"));
// 	printf("%d\n", atoi("1234"));
// 	printf("%d\n", atoi(" \n\t\v\f\r	1234"));
// 	printf("%d\n", atoi(" \n\t  \0  \v\f\r	+1234"));
// 	printf("%d\n", atoi(" \n\t  h  \v\f\r	1234"));
// 	printf("%d\n", atoi(" \n\t\v\f\r-1234"));
// 	printf("%d\n", atoi("hoge \n\t\v\f\r-1234"));
// 	printf("%d\n", atoi(" \n\t\v\f\r-1234a4"));
// 	printf("%d\n", atoi(" \n\t\v\f\r-2147483648a4"));
// 	printf("%d\n", atoi(" \n\t\v\f\r-2147483649a4"));
// 	printf("%d\n", atoi(" \n\t\v\f\r-2147483647a4"));
// 	printf("%d\n", atoi(" \n\t\v\f\r-2147483648a4"));
// 	return (0);
// }