/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:48:00 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/03 17:10:17 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_char(const char *s, char c)
{
	int		count;

	count = 0;
	if (s && c != 0)
	{
		while (*s != '\0')
		{
			while (*s == c && *s != '\0')
				s++;
			while (*s != c && *s != '\0')
				s++;
			count++;
		}
		return (count);
	}
	return (count);
}
