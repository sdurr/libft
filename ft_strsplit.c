/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 14:30:13 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/03 17:30:04 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		**ft_error(const char *s, char **ret)
{
	if (ft_strlen(s) == 0 || !s)
		ret[0] = NULL;
	else
	{
		ret[0] = ft_strdup(s);
		ret[1] = NULL;
	}
	return (ret);
}

static char		**ft_transfer(const char *s, char **ret, char c)
{
	int			i;
	int			j;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0' && i == 0)
			return (ft_error(s, ret));
		if (!(ret[i] = (char *)malloc(sizeof(char) * ft_word_long(s, c) + 1)))
			return (NULL);
		j = 0;
		while (*s != c && *s != '\0')
			ret[i][j++] = *s++;
		ret[i][j] = '\0';
		if (*s != '\0' || i == 0)
			i++;
	}
	ret[i] = NULL;
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ret;
	const char	*tmp;

	tmp = s;
	if (!(ret = (char **)malloc(sizeof(char *) * ft_count_char(s, c) + 1)))
		return (NULL);
	if (ft_strlen(s) == 0 || !c || *tmp == '\0')
		return (ft_error(s, ret));
	while (*tmp != c && *tmp != '\0')
		tmp++;
	if (*tmp == '\0')
		return (ft_error(s, ret));
	ret = ft_transfer(s, ret, c);
	return (ret);
}
