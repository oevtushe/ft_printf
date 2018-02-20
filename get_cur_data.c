/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cur_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:21:57 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:22:42 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** function return data from @param gdata arr by index readed from @param str
** in case of '$' appearence
** or by index @param di
*/

t_gdata		*get_cur_data(const char *str, size_t *idx, int *di, t_gdata **gd)
{
	int j;
	int ndi;

	j = *idx;
	if (ft_isdigit(str[j]))
	{
		ndi = ft_atoi(&str[j]) - 1;
		while (ft_isdigit(str[j]))
			++j;
		if (str[j] == '$')
		{
			*di = ndi;
			*idx = ++j;
		}
	}
	return (gd[(*di)++]);
}
