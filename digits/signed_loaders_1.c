/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_loaders_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:50:32 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:50:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

void	load_hhd(t_gdata *gdata, va_list ap)
{
	gdata->data.c = va_arg(ap, int);
	gdata->full_type->type = T_DEC;
	gdata->full_type->modifier = M_HH;
}

void	load_hd(t_gdata *gdata, va_list ap)
{
	gdata->data.si = va_arg(ap, int);
	gdata->full_type->type = T_DEC;
	gdata->full_type->modifier = M_H;
}

void	load_d(t_gdata *gdata, va_list ap)
{
	gdata->data.i = va_arg(ap, int);
	gdata->full_type->type = T_DEC;
	gdata->full_type->modifier = M_DEFAULT;
}

void	load_zd(t_gdata *gdata, va_list ap)
{
	gdata->data.sszi = va_arg(ap, ssize_t);
	gdata->full_type->type = T_DEC;
	gdata->full_type->modifier = M_Z;
}

void	load_jd(t_gdata *gdata, va_list ap)
{
	gdata->data.im = va_arg(ap, intmax_t);
	gdata->full_type->type = T_DEC;
	gdata->full_type->modifier = M_J;
}
