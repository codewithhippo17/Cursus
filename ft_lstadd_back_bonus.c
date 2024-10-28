/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:51:48 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/28 16:00:42 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
	new->next = NULL;
}

// #include <stdio.h>
// int main()
// {
// 	t_list **lst = malloc(sizeof(t_list *));
// 	t_list *new;
// 	// t_list *curent = *lst;

// 	char str[] = "hippo";
// 	*lst = ft_lstnew(str);

// 		char first1[] = "with";
// 	new = ft_lstnew(first1);

// 	ft_lstadd_front(lst, new);
// 	char first2[] = "code";
// 	new = ft_lstnew(first2);
// 	ft_lstadd_front(lst, new);
// 	t_list *curent = *lst;
// 	char	back[] = "back";
// 	new = ft_lstnew(back);
// 	ft_lstadd_back(lst, new);
// 	printf("%d\n", ft_lstsize(curent));
// 	printf("%s\n", (char *)(*lst)->content);
// 	printf("%s\n", (char *)(*lst)->next->content);
// 	printf("%s\n", (char *)(*lst)->next->next->content);
// 	printf("%s\n", (char *)(*lst)->next->next->next->content);

//     printf("the last node is :%s\n", (char *)ft_lstlast(*lst)->content);
// }