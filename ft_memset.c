/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:50:34 by sdurr             #+#    #+#             */
/*   Updated: 2014/11/28 11:40:35 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*rt;

	rt = b;
	i = 0;
	while (len != 0)
	{
		rt[i] = (char)c;
		i++;
		len--;
	}
	return (rt);
}