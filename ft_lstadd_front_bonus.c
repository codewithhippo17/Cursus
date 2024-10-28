/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:24:10 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/28 12:24:13 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new;
// 	new = malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }

// int main()
// {
// 	t_list **lst = malloc(sizeof(t_list *));
// 	t_list *new;

// 	char str[] = "code";
// 	*lst = ft_lstnew(str);
// 	char first[] = "hippo";
// 	new = ft_lstnew(first);	
// 	ft_lstadd_front(lst, new);
// 	printf("%s\n", (char *)(*lst)->content);
// 	printf("%s\n", (char *)(*lst)->next->content);
// }
