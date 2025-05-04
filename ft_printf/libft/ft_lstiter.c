/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:16:02 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 17:04:19 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>

// void	ft_putstr(void *s)
// {
// 	printf("%s\n", (char *)s);
// }

// int	main(void)
// {
// 	t_list	*head;

// 	head = ft_lstnew("Hello, World!");
// 	ft_lstadd_back(&head, ft_lstnew("Goodbye, Universe!"));
// 	ft_lstadd_back(&head, ft_lstnew("Bonjour, Monde!"));
// 	ft_lstiter(head, ft_putstr);
// 	//	ft_lstclear(&head, NULL);
// 	return (0);
// }
