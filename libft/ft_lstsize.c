
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *head = ft_lstnew("Hello, World!");
// 	ft_lstadd_front(&head, ft_lstnew("Goodbye, Universe!"));
// 	ft_lstadd_front(&head, ft_lstnew("Bonjour, Monde!"));

// 	printf("%d\n", ft_lstsize(head));
// 	printf("%d\n", ft_lstsize(NULL));

// 	return (0);
// }