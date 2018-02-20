/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:55 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:39:44 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** find_format find valid format string in @param str
** begin from @param start.
**
** @return format string if founded, also @param start and @param end
** initialized to start and end of format string respectively.
** @return NULL if no more format string in str.
*/

static char	*find_format(const char *str, size_t *start, size_t *end)
{
	char	*tmp;
	char	*res;
	size_t	pos;

	res = NULL;
	pos = *start;
	while ((tmp = ft_strchr(&str[pos], '%')))
	{
		pos = tmp - str;
		if ((res = get_format_string(str, &pos)))
		{
			*start = tmp - str;
			*end = pos;
			break ;
		}
		++pos;
	}
	return (res);
}

/*
** split_str fill plain and format lists.
** plain list will be filled with simple text.
** format list will be filled with format strings.
*/

void	split_string(const char *str, t_list **plain, t_list **format)
{
	size_t		start;
	size_t		end;
	size_t		prev;
	char		*tmp;

	start = 0;
	end = 0;
	prev = 0;
	while ((tmp = find_format(str, &start, &end)))
	{
		ft_lstaddelem(format, (void**)(&tmp), ft_strlen(tmp) + 1);
		tmp = ft_strsub(str, prev, start - prev);
		ft_lstaddelem(plain, (void**)(&tmp), ft_strlen(tmp) + 1);
		prev = end;
		start = end;
	}
	if (prev != ft_strlen(str))
	{
		tmp = ft_strsub(str, prev, ft_strlen(str) - prev);
		ft_lstaddelem(plain, (void**)(&tmp), ft_strlen(tmp) + 1);
	}
}
