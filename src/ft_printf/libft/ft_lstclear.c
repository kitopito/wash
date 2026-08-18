/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:15:47 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 17:05:20 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

// #include <stdio.h>

// void	del(void *content)
// {
// 	void	*hoge;

// 	hoge = content;
// }

// int	main(void)
// {
// 	t_list	*head;

// 	head = ft_lstnew("Hello, World!");
// 	ft_lstadd_back(&head, ft_lstnew("Goodbye, Universe!"));
// 	ft_lstadd_back(&head, ft_lstnew("Bonjour, Monde!"));
// 	ft_lstclear(&head, del);
// 	printf("%p\n", head);
// 	printf("%s\n", (char *)head->content);
// 	return (0);
// }
