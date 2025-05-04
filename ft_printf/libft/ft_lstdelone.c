/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:15:31 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 17:03:49 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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