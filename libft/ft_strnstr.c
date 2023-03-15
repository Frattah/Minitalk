/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:29:20 by frmonfre          #+#    #+#             */
/*   Updated: 2023/01/31 08:59:58 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ln;
	size_t	i;

	if (haystack == NULL && len == 0)
		return (NULL);
	if (*needle == 0)
		return ((char *)haystack);
	ln = ft_strlen(needle);
	i = 0;
	while (haystack[i])
	{
		if (i + ln > len)
			return (NULL);
		if (!ft_strncmp(haystack + i, needle, ln))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
