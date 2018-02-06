/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octals.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:40:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/01/13 14:55:03 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.c"

char	*octal_manager(va_list ap, t_format *sfmt)
{
	char	*res;

	res = NULL;
	if (sfmt->MODIFIER_l)
		res = form_value(va_arg(ap, unsigned long int), 0, sfmt, 8);
	else if (sfmt->MODIFIER_ll)
		res = form_value(va_arg(ap, unsigned long long int), 0, sfmt, 8);
	else if (sfmt->MODIFIER_j)
		res = form_value(va_arg(ap, uintmax_t), 0, sfmt, 8);
	else if (sfmt->MODIFIER_z)
		res = form_value(va_arg(ap, size_t), 0, sfmt, 8);
	else
		res = form_value(va_arg(ap, unsigned int), 0, sfmt, 8);
	return (res);
}
