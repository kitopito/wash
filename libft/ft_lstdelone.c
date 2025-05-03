
#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h>

// void	del(void *content)
// {
// 	void	*hoge;

// 	hoge = content;
// 	// content = 0;
// }

// int	main(void)
// {
// 	t_list *head = ft_lstnew("Hello, World!");
// 	ft_lstdelone(head, del);
// 	printf("%s\n", (char *)head->content);
// 	return (0);
// }