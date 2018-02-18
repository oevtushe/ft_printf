/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_add_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:46:18 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:46:19 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"
#include <stdlib.h>

void		str_add_prefix(char **str, char c)
{
	char	*tmp;
	char	*res;

	res = ft_strnew(1);
	if (res)
	{
		res[0] = c;
		tmp = res;
		res = ft_strjoin(res, *str);
		if (res)
		{
			ft_strdel(str);
			*str = res;
		}
		free(tmp);
	}
}
