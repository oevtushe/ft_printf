/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:40:32 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:40:34 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

void	str_modifiers(t_full_type *full_type, va_list ap, t_gdata *gdata)
{
	if (full_type->modifier == M_L || full_type->type == T_WSTR)
		gdata->data.pwc = va_arg(ap, wchar_t *);
	else
		gdata->data.pc = va_arg(ap, char *);
}
