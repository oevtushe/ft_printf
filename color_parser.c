/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:48:11 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/01 12:48:13 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

static char	*find_color_abbr(char *str, size_t *start, size_t *end)
{
	char	*tmp;
	char	*res;
	size_t	ts;
	size_t	te;

	res = NULL;
	if ((tmp = ft_strchr(str, '{')))
	{
		ts = tmp - str;
		if ((tmp = ft_strchr(tmp, '}')))
		{
			te = tmp - str;
			tmp = ft_strsub(str, ts, (te - ts) + 1);
			if ((res = get_color_code(tmp)))
			{
				*start = ts;
				*end = te + 1;
			}
			ft_strdel(&tmp);
		}
	}
	return (res);
}

/*
** Parces color in string. Collor abbreviature (RED, GREEN, etc.) should
** be in curly braces to be parsed.
** Examples of specifying color:
**	"{RED}Hi!{RESET}"
**	"{UNDERLINED}{MAGENTA}I'm underlined and purple.{RESET}"
** Exactly not only color but some options like underlined, bold, inverse
** could be specified too.
**
** @param	str		string to be parsed.
** @param	parsed	to write result in.
*/

void		color_parser(char *str, char **parsed)
{
	size_t		start;
	size_t		end;
	size_t		prev;
	char		*color;
	char		*simple;

	prev = 0;
	*parsed = ft_strnew(0);
	while ((color = find_color_abbr(&str[prev], &start, &end)))
	{
		simple = ft_strsub(str, prev, start);
		ft_strconnect(parsed, simple, 1);
		ft_strconnect(parsed, color, 1);
		ft_strdel(&simple);
		ft_strdel(&color);
		prev += end;
	}
	if (prev < ft_strlen(str))
		ft_strconnect(parsed, &str[prev], 1);
}
