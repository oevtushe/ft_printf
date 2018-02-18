/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:43 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:48:44 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

void	pos_modifiers(va_list ap, t_gdata *gdata)
{
	gdata->data.pv = va_arg(ap, void *);
	gdata->full_type->type = T_PS;
	gdata->full_type->modifier = M_DEFAULT;
}
