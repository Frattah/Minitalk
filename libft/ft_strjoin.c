/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:59:13 by frmonfre          #+#    #+#             */
/*   Updated: 2023/01/31 09:17:23 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s12;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s12 = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (s12 == NULL)
	{
		return (NULL);
	}
	while (++i < len1)
		s12[i] = s1[i];
	i = -1;
	while (++i < len2)
		s12[len1 + i] = s2[i];
	s12[len1 + i] = '\0';
	return (s12);
}
