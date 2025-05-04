/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:58:26 by ywada             #+#    #+#             */
/*   Updated: 2024/10/23 15:05:20 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*node;
// 	int		ft;

// 	node = ft_lstnew("Hello, World!");
// 	printf("%s\n", (char *)node->content);
// 	printf("%p\n", node->next);
// 	free(node);
// 	ft = 42;
// 	node = ft_lstnew(&ft);
// 	printf("%d\n", *(int *)node->content);
// 	printf("%p\n", node->next);
// 	free(node);
// 	return (0);
// }
