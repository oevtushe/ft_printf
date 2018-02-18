/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_decimals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:50:43 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:50:46 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

char		*unsigned_decimal_manager(t_format *sfmt, size_t *len)
{
	uintmax_t	uval;
	char		*res;

	sfmt->FLAG_PLUS = 0;
	sfmt->FLAG_SPACE = 0;
	decimal_flag_except(sfmt, 0);
	if (sfmt->gdata->full_type->type == T_LUNSIGNED)
		sfmt->gdata->full_type->modifier = M_L;
	uval = sfmt->gdata->data.uim;
	res = ft_uimtoa(uval);
	if (sfmt->FLAG_SQUOTE && MB_CUR_MAX > 0)
		group_by_thousands(&res);
	width_and_prec(&res, 0, sfmt);
	align(&res, sfmt);
	*len = ft_strlen(res);
	return (res);
}
