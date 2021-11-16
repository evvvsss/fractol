/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:15:10 by bferny            #+#    #+#             */
/*   Updated: 2021/11/16 23:15:11 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*element;

	while (*lst)
	{
		if ((*lst)->content)
			del((*lst)->content);
		element = *lst;
		*lst = element->next;
		free(element);
	}
	lst = NULL;
}
