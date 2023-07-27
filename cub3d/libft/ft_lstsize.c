/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:54:10 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/11/17 13:25:48 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}
