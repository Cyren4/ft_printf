/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:00:50 by cramdani          #+#    #+#             */
/*   Updated: 2019/11/24 21:00:52 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *cur;
	t_list *after;

	cur = *lst;
	if (*lst == NULL || del == NULL)
		return ;
	if (lst)
	{
		while (cur)
		{
			after = cur->next;
			ft_lstdelone(cur, del);
			cur = after;
		}
	}
	*lst = NULL;
}
