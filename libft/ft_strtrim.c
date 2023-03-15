/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:21:46 by frmonfre          #+#    #+#             */
/*   Updated: 2023/01/31 09:11:12 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isin(char c, char const *set)
{
	int	fnd;

	fnd = 0;
	while (*set && !fnd)
		if (*set++ == c)
			fnd = 1;
	return (fnd);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	i;
	size_t	j;
	char	*nw;

	i = 0;
	if (s == NULL || set == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] && isin(s[i], set))
		i++;
	while (i < j && isin(s[j], set))
		j--;
	nw = ft_substr(s, i, j - i + 1);
	return (nw);
}
