
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest == 0 && src == 0)
		return (0);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str1[80] = "The quick brown fox jumps over the lazy dog";
// 	char	str2[80] = "                                           ";
// 	char	str3[80] = "The quick brown fox jumps over the lazy dog";
// 	char	str4[80] = "                                           ";
// 	char	str5[80] = "The quick brown fox jumps over the lazy dog";
// 	char	str6[80] = "                                           ";

// 	memcpy(str1 + 10, str1, 40);
// 	printf("%s\n", str1);
// 	ft_memcpy(str4, str3, 40);
// 	printf("%s\n", str4);
// 	ft_memcpy(str5 + 10, str5, 40);
// 	printf("%s\n", str5);
// 	return (0);
// }
