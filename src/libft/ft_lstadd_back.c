
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = *lst;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	last_node->next = new;
}
//	new->next = NULL;

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *head = ft_lstnew("Hello, World!");
// 	ft_lstadd_front(&head, ft_lstnew("Goodbye, Universe!"));
// 	ft_lstadd_front(&head, ft_lstnew("Bonjour, Monde!"));

// 	//	t_list *headn = NULL;
// 	t_list **head_p = &head;
// 	ft_lstadd_back(head_p, ft_lstnew("Salut, le monde!"));

// 	t_list *current = head;
// 	while (current)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}

// 	return (0);
// }