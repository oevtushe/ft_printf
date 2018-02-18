/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:39:31 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:39:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

static void		load_wi(t_gdata *gdata, va_list ap)
{
	gdata->data.wi = va_arg(ap, wint_t);
	gdata->full_type->type = T_CHR;
	gdata->full_type->modifier = M_L;
}

static void		load_chr(t_gdata *gdata, va_list ap)
{
	gdata->data.c = va_arg(ap, int);
	gdata->full_type->type = T_CHR;
	gdata->full_type->modifier = M_DEFAULT;
}

void	chr_modifiers(char *type, va_list ap, t_gdata *gdata)
{
	if (type[0] == 'l' || type[0] == T_WCHR)
		load_wi(gdata, ap);
	else
		load_chr(gdata, ap);
}
