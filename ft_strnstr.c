/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:55:39 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/03 17:14:38 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;
	int c;

	i = 0;
	if (s2[i] == '\0')
		return ((char*)&s1[i]);
	while (s1[i] && n)
	{
		c = i;
		j = 0;
		if (s1[i - 1] == s2[j])
			i--;
		j = 0;
		while (s2[j++] == s1[i++] && n > 0)
		{
			n--;
			if (s2[j] == '\0' && s2[0] == s1[c])
				return ((char*)&s1[c]);
		}
		i = c;
		i++;
		n--;
	}
	return (NULL);
}
