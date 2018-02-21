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
** Find valid format string in @param str
** start from @param start.
**
** @param	str			string format is searching in.
** @param	start		index in string format is searching from.
** @param	end			index to end of format string.
** @param	mi_error	set to 1 when mixed indexation has place in the string
**						otherwise set to 0.
** @return				format string if found, also @param start and @param end
** 						initialized to start and end of format string respectively.
** @return	NULL		if no more valid format string in @param str.
*/

static char	*find_format(const char *str, size_t *start, size_t *end, int *mi_error)
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
			if (!validate_mixed_index(str))
			{
				*end = ft_strlen(str);
				*mi_error = 1;
				ft_strdel(&res);
				break ;
			}
			*start = tmp - str;
			*end = pos;
			break ;
		}
		++pos;
	}
	return (res);
}

static void	mi_err_handler(const char *str, t_list **plain, t_list **format)
{
	ft_lstdel(plain, del_simple);
	ft_lstdel(format, del_simple);
	*plain = ft_lstnew(str, ft_strlen(str) + 1);
}

/*
** Fill @param plain and @param format lists.
** Invalid format strings will be interpretated as
** simple text.
**
** If string contain mixed index format like '%4$.*d',
** whole string will be interpretated as simple text.
**
** @param	plain	list with simple text.
** @param	extra	list with format strings.
*/

void		split_string(const char *str, t_list **plain, t_list **format)
{
	size_t		start;
	size_t		end;
	size_t		prev;
	char		*tmp;
	int			mi_error;

	start = 0;
	end = 0;
	prev = 0;
	mi_error = 0;
	while ((tmp = find_format(str, &start, &end, &mi_error)))
	{
		ft_lstaddelem(format, (void**)(&tmp), ft_strlen(tmp) + 1);
		tmp = ft_strsub(str, prev, start - prev);
		ft_lstaddelem(plain, (void**)(&tmp), ft_strlen(tmp) + 1);
		prev = end;
		start = end;
	}
	if (mi_error)
		mi_err_handler(str, plain, format);
	else if (prev < ft_strlen(str))
	{
		tmp = ft_strsub(str, prev, ft_strlen(str) - prev);
		ft_lstaddelem(plain, (void**)(&tmp), ft_strlen(tmp) + 1);
	}
	validate_lists(str, plain, format);
}
