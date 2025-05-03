#include "libft.h"
#include <limits.h>

int	ft_isint(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -sign;
	}
	if (ft_strall(str + i, ft_isdigit) == 0)
		return (0);
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + sign * (str[i] - '0');
		if (result > INT_MAX || result < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_isint("1234"));
// 	printf("%d\n", ft_isint("+1234"));
// 	printf("%d\n", ft_isint("-1234"));
// 	printf("%d\n", ft_isint("1234a"));
// 	printf("%d\n", ft_isint("1234a4"));
// 	printf("%d\n", ft_isint("0"));
// 	printf("%d\n", ft_isint("+0"));
// 	printf("%d\n", ft_isint("-0"));
// 	printf("%d\n", ft_isint("9223372036854775807"));
// 	printf("%d\n", ft_isint("-9223372036854775807"));
// 	printf("%d\n", ft_isint("-9223a"));
// 	printf("%d\n", ft_isint("9223a3"));
// 	printf("%d\n", ft_isint("2147483647"));
// 	printf("%d\n", ft_isint("2147483648"));
// 	printf("%d\n", ft_isint("-2147483648"));
// 	printf("%d\n", ft_isint("-2147483649"));
// }

// gcc ft_isint.c ft_strall.c ft_isdigit.c