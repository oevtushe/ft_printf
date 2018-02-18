/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:49:45 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:49:46 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

char		*octal_manager(t_format *sfmt, size_t *len)
{
	uintmax_t	uval;
	char		*res;

	sfmt->FLAG_PLUS = 0;
	sfmt->FLAG_SPACE = 0;
	decimal_flag_except(sfmt, 0);
	uval = sfmt->gdata->data.uim;
	res = ft_uimtoabase_gen(uval, 0, 8);
	width_and_prec(&res, 0, sfmt);
	if (sfmt->FLAG_SHARP && res[0] != '0')
		str_add_prefix(&res, '0');
	align(&res, sfmt);
	*len = ft_strlen(res);
	return (res);
}
