/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:49:39 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:42:06 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

char		*hex_manager(t_format *sfmt, size_t *len)
{
	uintmax_t	uval;
	char		*res;

	sfmt->flag_plus = 0;
	sfmt->flag_space = 0;
	uval = sfmt->gdata->data.uim;
	res = ft_uimtoabase_gen(uval, 0, 16);
	if (sfmt->flag_sharp && uval)
	{
		zeroes_handling(&res, 2, sfmt);
		if (sfmt->gdata->full_type->type == T_BHEX)
			ft_strconnect(&res, "0X", -1);
		else
			ft_strconnect(&res, "0x", -1);
	}
	else
		zeroes_handling(&res, 0, sfmt);
	spaces_handling(&res, sfmt);
	*len = ft_strlen(res);
	return (res);
}
