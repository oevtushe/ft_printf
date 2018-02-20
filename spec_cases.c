/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:39:16 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:39:23 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** In case of wrong format string
** function return copy of that one
*/

void	spec_cases(const char *str, t_format *sfmt)
{
	t_gdata	*gdata;

	gdata = (t_gdata *)ft_memalloc(sizeof(t_gdata));
	gdata->full_type = (t_ftype *)ft_memalloc(sizeof(t_ftype));
	if (str[1] == '%')
		gdata->full_type->type = T_PT;
	else
	{
		gdata->data.pc = ft_strdup(str);
		gdata->full_type->type = T_UNDEF;
		gdata->full_type->modifier = M_DEFAULT;
	}
	sfmt->gdata = gdata;
}
