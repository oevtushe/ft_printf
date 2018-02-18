/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_loaders_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:50:36 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:50:37 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

void	load_ld(t_gdata *gdata, va_list ap)
{
	gdata->data.li = va_arg(ap, long int);
	gdata->full_type->type = T_DEC;
	gdata->full_type->modifier = M_L;
}

void	load_lld(t_gdata *gdata, va_list ap)
{
	gdata->data.lli = va_arg(ap, long long int);
	gdata->full_type->type = T_DEC;
	gdata->full_type->modifier = M_LL;
}
