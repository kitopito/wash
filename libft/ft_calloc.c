
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;
	size_t			mem_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (0xFFFFFFFFFFFFFFFF / nmemb < size)
		return (NULL);
	mem_size = nmemb * size;
	p = malloc(mem_size);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < mem_size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*p;
// 	int		*pi;
// 	int		*pp;
// 	int		*pz;

// 	p = ft_calloc(10, sizeof(char));
// 	p[0] = 'a';
// 	p[1] = 'b';
// 	p[2] = 'c';
// 	printf("%s\n", p);
// 	free(p);
// 	pi = ft_calloc(10, sizeof(int));
// 	for (int i = 0; i < 10; i++)
// 		printf("%d ", pi[i]);
// 	printf("\n");
// 	free(pi);
// 	pp = ft_calloc(4294967296, 4294967296);
// 	if (pp == NULL)
// 		printf("null\n");
// 	pp = ft_calloc(3 * 5 * 17 * 257L * 641L * 65537L, 6700417);
// 	if (pp == NULL)
// 		printf("null\n");
// 	free(pp);
// 	pz = ft_calloc(0, 2147483648);
// 	if (pz == NULL)
// 		printf("null\n");
// 	free(pz);
// 	return (0);
// }
