/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:16:15 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 17:04:44 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == NULL)
		return (NULL);
	lst = lst->next;
	current = new_lst;
	while (lst != NULL)
	{
		current->next = ft_lstnew(f(lst->content));
		if (current->next == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		current = current->next;
		lst = lst->next;
	}
	return (new_lst);
}

// #include <stdio.h>

// void	del(void *content)
// {
// 	free(content);
// 	content = NULL;
// }

// void	*upper(void *content)
// {
// 	const char	*str;
// 	int			i;
// 	char		*new_str;

// 	str = (const char *)content;
// 	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] >= 'a' && str[i] <= 'z')
// 			new_str[i] = str[i] - 32;
// 		else
// 			new_str[i] = str[i];
// 		i++;
// 	}
// 	new_str[i] = '\0';
// 	return (new_str);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*new_head;

// 	head = ft_lstnew("Hello, World!");
// 	ft_lstadd_back(&head, ft_lstnew("Goodbye, Universe!"));
// 	ft_lstadd_back(&head, ft_lstnew("Bonjour, Monde!"));
// 	new_head = ft_lstmap(head, upper, del);
// 	while (new_head)
// 	{
// 		printf("%s\n", (char *)new_head->content);
// 		new_head = new_head->next;
// 	}
// 	ft_lstclear(&head, del);
// 	ft_lstclear(&new_head, del);
// 	return (0);
// }
