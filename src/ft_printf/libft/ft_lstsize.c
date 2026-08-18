/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:14:26 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 15:23:13 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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