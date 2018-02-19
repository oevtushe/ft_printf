/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:40:13 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:40:17 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

static char 		*str_null(t_format *sfmt, size_t *ln)
{
	char *res;

	sfmt->gdata->data.pc = ft_strdup("(null)");
	res = str_manager(sfmt, ln);
	ft_strdel(&sfmt->gdata->data.pc);
	*ln = ft_strlen(res);
	return (res);
}

char				*str_manager(t_format *sfmt, size_t *ln)
{
	char *res;

	if (sfmt->gdata->data.pc == NULL)
		res = str_null(sfmt, ln);
	else
	{
		if (sfmt->gdata->full_type->modifier == M_L || sfmt->gdata->full_type->type == T_WSTR)
			res = wcs_to_utf8(sfmt->gdata->data.pwc, sfmt->precision);
		else
		{
			if (sfmt->precision >= 0)
			{
				res = ft_strnew(sfmt->precision);
				ft_memcpy(res, sfmt->gdata->data.pc, sfmt->precision);
			}
			else
				res = ft_strdup(sfmt->gdata->data.pc);
		}
		align(&res, sfmt);
		*ln = ft_strlen(res);
	}
	return (res);
}