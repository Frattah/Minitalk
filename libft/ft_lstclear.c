/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:37:57 by frmonfre          #+#    #+#             */
/*   Updated: 2023/01/27 15:59:42 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cpy;

	if (lst != NULL && (*lst)->next != NULL && del != NULL)
	{
		while (lst != NULL && *lst != NULL)
		{
			cpy = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = cpy;
		}
	}
}
