
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;

	p = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		*p = ch;
		p++;
	}
	return (s);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char buf[1024] = "hello";
// 	memset(buf, 'x', 5);
// 	printf("%s\n", buf);
// 	//	memset(buf, 'x', 5000);
// 	// A segmentation fault will occurr if n is larger than buffer size
// 	memset(buf, 256 + 'A', 5);
// 	// Overflow: 256+'A' exceeds char range,so 321 % 256 = 'A' is actually used
// 	printf("%s\n", buf);
// 	memset(buf, 255, 5);
// 	printf("%d\n", buf[0]);
// 	ft_memset(buf, 256 + 'A', 5);
// 	printf("%s\n", buf);
// 	ft_memset(buf, 255, 5);
// 	printf("%d\n", buf[0]);
// 	return (0);
// }