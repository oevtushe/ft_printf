/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:18 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:34:20 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** get_format_string validates format string beginning
** at @param idx in @param str.
** @return format string if is valid.
** @return NULL if format string not valid.
*/

char	*get_format_string(const char *str, size_t *idx)
{
	size_t		start;
	char		*res;
	size_t		res_idx;

	res = NULL;
	start = *idx;
	res_idx = *idx + 1;
	read_data_index(str, &res_idx);
	read_flags(str, &res_idx);
	read_width(str, &res_idx);
	read_precision(str, &res_idx);
	read_modifiers(str, &res_idx);
	if (is_type(str[res_idx]))
	{
		++res_idx;
		res = ft_strsub(str, start, res_idx - start);
		*idx = res_idx;
	}
	else
		res = NULL;
	return (res);
}
