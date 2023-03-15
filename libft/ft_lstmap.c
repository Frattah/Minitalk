/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:37:02 by frmonfre          #+#    #+#             */
/*   Updated: 2023/01/29 11:34:41 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nw;
	t_list	*tmp;
	t_list	*cpy;

	nw = NULL;
	cpy = lst;
	while (cpy != NULL)
	{
		tmp = ft_lstnew(f(cpy->content));
		if (tmp == NULL)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&nw, tmp);
		cpy = cpy->next;
	}
	return (nw);
}
