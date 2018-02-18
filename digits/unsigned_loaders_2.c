/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_loaders_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:50:53 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:50:57 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

void	load_hu(t_gdata *gdata, va_list ap)
{
	gdata->data.usi = va_arg(ap, unsigned int);
	gdata->full_type->modifier = M_H;
	gdata->full_type->type = T_UNSIGNED;
}

void	load_hhu(t_gdata *gdata, va_list ap)
{
	gdata->data.uc = va_arg(ap, unsigned int);
	gdata->full_type->modifier = M_HH;
	gdata->full_type->type = T_UNSIGNED;
}
