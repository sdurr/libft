/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:49:58 by getrembl          #+#    #+#             */
/*   Updated: 2014/12/27 11:10:26 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# define	BUFF_SIZE	10

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

int			get_next_line(int const fd, char **line);

#endif
