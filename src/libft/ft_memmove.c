
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest == 0 && src == 0)
		return (0);
	if (dest <= src)
	{
		s = (unsigned char *)src;
		d = (unsigned char *)dest;
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d = (unsigned char *)dest + n - 1;
		s = (unsigned char *)src + n - 1;
		while (n--)
			*d-- = *s--;
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
// 	char	str7[80] = "The quick brown fox jumps over the lazy dog";
// 	char	str8[80] = "                                           ";

// 	memmove(str2, str1, 40);
// 	printf("%s\n", str2);
// 	memmove(str3 + 10, str3, 40);
// 	printf("%s\n", str3);
// 	printf("%s\n", memmove(0, 0, 40));
// 	ft_memmove(str6, str5, 40);
// 	printf("%s\n", str6);
// 	ft_memmove(str7 + 10, str7, 40);
// 	printf("%s\n", str7);
// 	printf("%s\n", ft_memmove(0, 0, 40));
// 	return (0);
// }
