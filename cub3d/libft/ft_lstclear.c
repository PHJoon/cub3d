/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:59:32 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/11/17 13:24:45 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = *lst;
	if (ptr == NULL || del == NULL)
	{
		*lst = NULL;
		return ;
	}
	while (ptr)
	{
		tmp = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = tmp;
	}
	*lst = NULL;
}
