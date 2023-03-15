/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:08:40 by frmonfre          #+#    #+#             */
/*   Updated: 2023/01/31 10:21:20 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*out;

	if (s == NULL)
		return (NULL);
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	out = (char *) malloc(sizeof(char) * (len + 1));
	if (out == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		out[0] = 0;
		return (out);
	}
	i = start - 1;
	while (s[++i] && i < len + start)
		out[i - start] = s[i];
	out[i - start] = '\0';
	return (out);
}
