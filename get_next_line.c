/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:48:43 by getrembl          #+#    #+#             */
/*   Updated: 2014/12/27 11:09:06 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**    int read(int fd, char *buf, int count);
**    fd = File descriptor depuis leauel lire;
**    buf = buffer de destination;
**    count = Nombre d\'octets a lire;
**
**    Retourne le nombre d\'octets lus ou -1 en cas d\'erreur;
*/

int 				get_next_line(int const fd, char **line)
{
	int				ret;
	char			*buf;
	static char		*bkp = NULL;
	char			*bkp_join;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	ret = 1;
	if (!bkp && (bkp = ft_strnew(1)) == NULL)
		return (-1);
	while (ret > 0)
	{
		buf = ft_strnew(BUFF_SIZE + 1);
		if((ret = read(fd, buf, BUFF_SIZE)) != EOF && ret > 0)
		{
			buf[ret] = '\0';
			bkp = ft_strjoin(bkp, buf);
		}
		if ((bkp_join = ft_strchr(bkp, '\n')) != NULL)
		{
			*bkp_join = '\0';
			if (!(*line = ft_strdup(bkp)))
				return (-1);
			ft_memmove(bkp, bkp_join + 1, ft_strlen(bkp_join + 1) + 1);
			return (1);
		}
	}
	if (!(*line = ft_strdup(bkp)))
		return (-1);
	bkp = ft_strnew(1);
	return (ret);
}
