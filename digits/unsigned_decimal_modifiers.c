/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_decimal_modifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:50:40 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:50:41 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

void	unsigned_decimal_modifiers(char *str, va_list ap, t_gdata *gdata)
{
	if (str[0] == 'l' && str[1] == 'l')
		load_llu(gdata, ap);
	else if (str[0] == 'l' || str[0] == T_LUNSIGNED)
		load_lu(gdata, ap);
	else if (str[0] == 'h' && str[1] == 'h')
		load_hhu(gdata, ap);
	else if (str[0] == 'h')
		load_hu(gdata, ap);
	else if (str[0] == 'j')
		load_ju(gdata, ap);
	else if (str[0] == 'z')
		load_zu(gdata, ap);
	else
		load_u(gdata, ap);
}
