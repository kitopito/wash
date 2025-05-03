
#include "libft.h"
#include <stdlib.h>

char	*ft_strconcat(char **argv)
{
	size_t	total_length;
	char	*result;
	size_t	i;
	size_t	k;

	total_length = 0;
	i = 0;
	while (argv[i] != NULL)
	{
		total_length += ft_strlen(argv[i]);
		i++;
	}
	result = malloc(sizeof(char) * (total_length + 1));
	if (result == NULL)
		return (NULL);
	result[total_length] = '\0';
	i = 0;
	k = 0;
	while (argv[i] != NULL)
	{
		ft_strlcpy(result + k, argv[i], total_length);
		k += ft_strlen(argv[i]);
		i++;
	}
	return (result);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*strings[] = {"Hello", " ", "World", "!", NULL};
// 	char	*result;

// 	result = ft_strconcat(strings);
// 	printf("%s\n", result);
// 	free(result); // メモリ解放
// 	return (0);
// }
