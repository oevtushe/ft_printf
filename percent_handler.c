/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 15:15:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/23 15:15:59 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** In case of wrong format string
** function return copy of that one
*/

void	percent_handler(const char *str, t_format *sfmt)
{
	t_gdata	*gdata;

	gdata = (t_gdata *)ft_memalloc(sizeof(t_gdata));
	gdata->full_type = (t_ftype *)ft_memalloc(sizeof(t_ftype));
	if (str[1] == '%')
		gdata->full_type->type = T_PT;
	else
	{
		gdata->full_type->type = T_UNDEF;
		gdata->full_type->modifier = M_DEFAULT;
		gdata->data.pc = ft_strdup(str);
	}
	sfmt->gdata = gdata;
}
