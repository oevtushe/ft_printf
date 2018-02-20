/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_decimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:50:26 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:42:43 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

static void			handle_signs(t_format *sfmt, char **res, int sign)
{
	if (sfmt->flag_plus)
		str_add_prefix(res, '+');
	else if (sfmt->flag_space)
		str_add_prefix(res, ' ');
	else if (sign < 0)
		str_add_prefix(res, '-');
}

static intmax_t		signed_modifiers(t_gdata *gdata)
{
	intmax_t vl;

	vl = 0;
	if (gdata->full_type->modifier == M_L)
		vl = gdata->data.li;
	else if (gdata->full_type->modifier == M_LL)
		vl = gdata->data.lli;
	else if (gdata->full_type->modifier == M_H)
		vl = gdata->data.si;
	else if (gdata->full_type->modifier == M_HH)
		vl = gdata->data.c;
	else if (gdata->full_type->modifier == M_J)
		vl = gdata->data.im;
	else if (gdata->full_type->modifier == M_Z)
		vl = gdata->data.sszi;
	else
		vl = gdata->data.i;
	return (vl);
}

char				*signed_decimal_manager(t_format *sfmt, size_t *len)
{
	int			sign;
	intmax_t	val;
	uintmax_t	uval;
	char		*res;

	sign = 0;
	if (sfmt->gdata->full_type->type == T_LDEC)
		sfmt->gdata->full_type->modifier = M_L;
	val = signed_modifiers(sfmt->gdata);
	if (val >= 0 && (sfmt->flag_plus || sfmt->flag_space))
		sign = 1;
	else if (val < 0)
		sign = -1;
	decimal_flag_except(sfmt, (sign < 0));
	uval = (sign < 0) ? (val * -1L) : val;
	res = ft_uimtoa(uval);
	if (sfmt->flag_squote && MB_CUR_MAX > 1)
		group_by_thousands(&res);
	width_and_prec(&res, ft_abs(sign), sfmt);
	handle_signs(sfmt, &res, sign);
	align(&res, sfmt);
	*len = ft_strlen(res);
	return (res);
}
