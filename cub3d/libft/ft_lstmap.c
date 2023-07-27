/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:01:21 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/11/18 19:22:20 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*free_lst(t_list *ptr, void (*del)(void *))
{
	t_list	*t;

	t = ptr;
	while (ptr)
	{
		t = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = t;
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new;
	t_list	*before;
	int		cnt;

	cnt = 0;
	ptr = NULL;
	if (lst == 0 || f == 0 || del == 0)
		return (0);
	while (lst)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
			return (free_lst(ptr, del));
		new->content = f(lst->content);
		new->next = NULL;
		if (cnt++ == 0)
			ptr = new;
		else
			before->next = new;
		before = new;
		lst = lst->next;
	}
	return (ptr);
}
