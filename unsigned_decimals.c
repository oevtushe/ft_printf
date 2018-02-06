/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_decimals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:26:49 by oevtushe          #+#    #+#             */
/*   Updated: 2018/01/13 13:26:14 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.c"

/* may be unsigned char and unsigned short needed */
char	*unsigned_decimal_manager(va_list ap, t_format *sfmt)
{
	char	*res;

	res = NULL;
	if (sfmt->MODIFIER_l)
		res = form_value(va_arg(ap, unsigned long int), sfmt, 10);
	else if (sfmt->MODIFIER_ll)
		res = form_value(va_arg(ap, unsigned long long int), sfmt, 10);
	else if (sfmt->MODIFIER_j)
		res = form_value(va_arg(ap, uintmax_t), sfmt, 10);
	else if (sfmt->MODIFIER_z)
		res = form_value(va_arg(ap, size_t), sfmt, 10);
	else
		res = form_value(va_arg(ap, unsigned int), sfmt, 10);
	return (res);
}
