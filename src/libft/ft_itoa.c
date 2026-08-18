
#include <stdlib.h>

static size_t	int_length(int n)
{
	size_t	length;

	if (n == 0)
		return (1);
	length = 0;
	if (n < 0)
		length++;
	while (n != 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	size_t	length;
	int		sign;
	char	*result;

	length = int_length(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	result[length--] = '\0';
	while (length > 0)
	{
		result[length] = '0' + sign * (n % 10);
		n /= 10;
		length--;
	}
	if (sign == -1)
		result[0] = '-';
	else
		result[0] = '0' + sign * (n % 10);
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *str = ft_itoa(42);
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_itoa(-42);
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_itoa(2147483647);
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_itoa(-2147483648);
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_itoa(0);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }