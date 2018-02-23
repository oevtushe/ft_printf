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

void	percent_handler(t_format *sfmt)
{
	t_gdata	*gdata;

	gdata = (t_gdata *)ft_memalloc(sizeof(t_gdata));
	gdata->full_type = (t_ftype *)ft_memalloc(sizeof(t_ftype));
	gdata->full_type->type = T_PT;
	sfmt->gdata = gdata;
}
