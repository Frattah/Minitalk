/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:53:05 by frmonfre          #+#    #+#             */
/*   Updated: 2023/01/31 10:46:05 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ln;
	size_t	i;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	ln = ft_strlen(dst);
	i = -1;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (ln < dstsize - 1 && dstsize > 0)
	{
		while (src[++i] && ln + i < dstsize - 1)
			dst[ln + i] = src[i];
		dst[ln + i] = '\0';
	}
	if (ln > dstsize)
		ln = dstsize;
	return (ln + ft_strlen(src));
}
