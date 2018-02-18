/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:18 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:48:19 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

void read_type(const char *str, size_t *idx)
{
	if (ft_strchr(ALL_TYPES, str[*idx]))
		(*idx)++;
}

/*
** Castilla for %%
*/

char	*get_format_string(const char *str, size_t *idx)
{
	size_t		start;
	char		*res;

	res = NULL;
	start = (*idx)++;
	read_data_index(str, idx);
	read_flags(str, idx);
	read_width(str, idx);
	read_precision(str, idx);
	read_modifiers(str, idx);
	if (str[*idx])
		++(*idx);
	res = ft_strsub(str, start, *idx - start);
	return (res);
}