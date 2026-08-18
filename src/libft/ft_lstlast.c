
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *head = ft_lstnew("Hello, World!");
// 	ft_lstadd_front(&head, ft_lstnew("Goodbye, Universe!"));
// 	ft_lstadd_front(&head, ft_lstnew("Bonjour, Monde!"));

// 	printf("%s\n", (char *)ft_lstlast(head)->content);
// 	printf("%p\n", ft_lstlast(NULL));

// 	return (0);
// }