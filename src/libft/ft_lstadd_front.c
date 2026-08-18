
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *head = ft_lstnew("Hello, World!");
// 	ft_lstadd_front(&head, ft_lstnew("Goodbye, Universe!"));
// 	ft_lstadd_front(&head, ft_lstnew("Bonjour, Monde!"));

// 	t_list *current = head;
// 	while (current)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	return (0);
// }