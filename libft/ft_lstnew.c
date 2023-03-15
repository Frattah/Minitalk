/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:33:10 by frmonfre          #+#    #+#             */
/*   Updated: 2023/01/29 08:51:30 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nw;

	nw = (t_list *) malloc(sizeof(t_list));
	if (nw == NULL)
		return (NULL);
	nw->content = content;
	nw->next = NULL;
	return (nw);
}
