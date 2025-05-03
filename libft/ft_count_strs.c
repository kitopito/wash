
#include <stddef.h>

size_t	ft_count_strs(char **strs)
{
	size_t	count;

	count = 0;
	while (strs[count] != NULL)
	{
		count++;
	}
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	size_t	count;

// 	char *strs[] = {"Hello", "world", "this", "is", "a", "test", NULL};
// 		// NULL marks the end of the array
// 	count = ft_count_strs(strs);
// 	printf("The number of strings is: %zu\n", count); // Output: 6
// 	return (0);
// }
