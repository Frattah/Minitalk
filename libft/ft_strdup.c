/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:29:33 by frmonfre          #+#    #+#             */
/*   Updated: 2023/01/31 10:42:53 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*nw;
	size_t	len;

	len = ft_strlen(s1) + 1;
	nw = (char *) malloc(sizeof(char) * len);
	if (nw == NULL)
		return (NULL);
	ft_strlcpy(nw, s1, len);
	return (nw);
}
