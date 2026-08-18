
#include "libft.h"
#include <limits.h>

static int	check_overflow(long num, char c, int sign)
{
	int	digit;

	digit = sign * (c - '0');
	if (sign > 0)
	{
		if (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && digit > LONG_MAX
				% 10))
			return (0);
		else
			return (1);
	}
	else
	{
		if (num < LONG_MIN / 10 || (num == LONG_MIN / 10 && digit < LONG_MIN
				% 10))
			return (0);
		else
			return (1);
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0' && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -sign;
	}
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
	{
		if (check_overflow(result, str[i], sign))
			result = result * 10 + sign * (str[i] - '0');
		else if (sign == 1)
			return ((int)LONG_MAX);
		else
			return ((int)LONG_MIN);
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
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r21474836488888a4"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r11424236488888a4"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r9223372036854775806a4"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r9223372036854775807a4"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r9223372036854775808a4"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r-9223372036854775808a4"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r-9223372036854775809a4"));
// 	printf("%d\n", ft_atoi(" \n\t\v\f\r1000000000000000000000000000000a4"));
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
// 	printf("%d\n", atoi(" \n\t\v\f\r11424236488888a4"));
// 	printf("%d\n", atoi(" \n\t\v\f\r9223372036854775806a4"));
// 	printf("%d\n", atoi(" \n\t\v\f\r9223372036854775807a4"));
// 	printf("%d\n", atoi(" \n\t\v\f\r9223372036854775808a4"));
// 	printf("%d\n", atoi(" \n\t\v\f\r-9223372036854775808a4"));
// 	printf("%d\n", atoi(" \n\t\v\f\r-9223372036854775809a4"));
// 	printf("%d\n", atoi(" \n\t\v\f\r1000000000000000000000000000000a4"));
// 	return (0);
// }