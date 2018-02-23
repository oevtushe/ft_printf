/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:46:14 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:46:15 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

/*
** Recreates string @param str with @param new_len length.
** Oldlength - newlength characters from side specified in @param side
** (where -1 means left, 1 right) will be filled with @param filler character.
*/

void	spc_string(char **str, size_t new_len, char filler, int side)
{
	size_t	tjlen;
	char	*res;
	char	*to_join;

	tjlen = new_len - ft_strlen(*str);
	to_join = ft_strnew(tjlen);
	if (to_join)
	{
		ft_memset(to_join, filler, tjlen);
		if (side == 1)
			res = ft_strjoin(*str, to_join);
		else
			res = ft_strjoin(to_join, *str);
		ft_strdel(str);
		ft_strdel(&to_join);
		*str = res;
	}
}
