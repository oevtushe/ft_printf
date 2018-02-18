/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:49:39 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:49:41 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

char		*hex_manager(t_format *sfmt, size_t *len)
{
	uintmax_t	uval;
	char		*res;
	char		*tmp;

	sfmt->FLAG_PLUS = 0;
	sfmt->FLAG_SPACE = 0;
	uval = sfmt->gdata->data.uim;
	res = ft_uimtoabase_gen(uval, 0, 16);
	if (sfmt->FLAG_SHARP && uval)
	{
		width_and_prec(&res, 2, sfmt);
		tmp = res;
		res = ft_strjoin("0x", res);
		ft_strdel(&tmp);
	}
	else
		width_and_prec(&res, 0, sfmt);
	if (sfmt->gdata->full_type->type == T_BHEX)
		ft_strtoupper(res);
	align(&res, sfmt);
	*len = ft_strlen(res);
	return (res);
}