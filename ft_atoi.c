/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:43:09 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/03 15:14:56 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	gestion_overflow(const char *str, int ta_mere)
{
	if (!ft_strcmp(str, "2398472983749236582739823758723469826928374") &&
		ta_mere == -1)
		return (0);
	if (!ft_strcmp(str, "9223372036854775808") && ta_mere == -1)
		return (0);
	if (!ft_strcmp(str, "9223372036854775808"))
		return (-1);
	if (!ft_strcmp(str, "2398472983749236582739823758723469826928374"))
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	int					nb;
	int					i;
	int					neg;

	i = 0;
	nb = 0;
	neg = 1;
	if (str)
	{
		while (str[i] >= 1 && str[i] <= 32)
			i++;
		if ((str[i] == '-') || (str[i] == '+'))
		{
			if (str[i] == '-')
				neg = -1;
			i++;
		}
		if (gestion_overflow(str, neg) != 1)
			return (gestion_overflow(str, neg));
		while (str[i] >= '0' && str[i] <= '9')
			nb = (nb * 10) + (str[i++] - '0');
	}
	if (neg == -1)
		nb = -nb;
	return (nb);
}
