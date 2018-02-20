/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outside_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:38:26 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:38:35 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** function get data from @param gdata by index in @param str
*/

int	outside_param(const char *str, size_t *idx, t_gdata **gdata, int *di)
{
	int	val;

	val = -1;
	if (ft_isdigit(str[*idx]))
	{
		*di = ft_atoi(&str[*idx]) - 1;
		while (ft_isdigit(str[*idx]))
			++(*idx);
		if (str[*idx] == '$')
		{
			++(*idx);
			val = gdata[*di]->data.i;
		}
	}
	else
		val = gdata[(*di)++]->data.i;
	return (val);
}
