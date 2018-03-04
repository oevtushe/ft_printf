/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:49:00 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/04 12:44:34 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

static char	*search_in_options(char *abbr)
{
	if (!ft_strcmp(abbr, "BOLD"))
		return (ft_strdup(BOLD));
	else if (!ft_strcmp(abbr, "DBOLD"))
		return (ft_strdup(DBOLD));
	else if (!ft_strcmp(abbr, "NBOLD"))
		return (ft_strdup(NBOLD));
	else if (!ft_strcmp(abbr, "UNDERLINE"))
		return (ft_strdup(UNDERLINE));
	else if (!ft_strcmp(abbr, "NUNDERLINE"))
		return (ft_strdup(NUNDERLINE));
	else if (!ft_strcmp(abbr, "INVERSE"))
		return (ft_strdup(INVERSE));
	else if (!ft_strcmp(abbr, "NINVERSE"))
		return (ft_strdup(NINVERSE));
	else if (!ft_strcmp(abbr, "RESET"))
		return (ft_strdup(RESET));
	else
		return (NULL);
}

static char	*search_in_text_colors(char *abbr)
{
	if (!ft_strcmp(abbr, "BLACK"))
		return (ft_strdup(BLACK));
	else if (!ft_strcmp(abbr, "RED"))
		return (ft_strdup(RED));
	else if (!ft_strcmp(abbr, "GREEN"))
		return (ft_strdup(GREEN));
	else if (!ft_strcmp(abbr, "YELLOW"))
		return (ft_strdup(YELLOW));
	else if (!ft_strcmp(abbr, "BLUE"))
		return (ft_strdup(BLUE));
	else if (!ft_strcmp(abbr, "MAGENTA"))
		return (ft_strdup(MAGENTA));
	else if (!ft_strcmp(abbr, "CYAN"))
		return (ft_strdup(CYAN));
	else if (!ft_strcmp(abbr, "GRAY"))
		return (ft_strdup(GRAY));
	else
		return (NULL);
}

static char	*search_in_background_colors(char *abbr)
{
	if (!ft_strcmp(abbr, "BGBLACK"))
		return (ft_strdup(BGBLACK));
	else if (!ft_strcmp(abbr, "BGRED"))
		return (ft_strdup(BGRED));
	else if (!ft_strcmp(abbr, "BGGREEN"))
		return (ft_strdup(BGGREEN));
	else if (!ft_strcmp(abbr, "BGBROWN"))
		return (ft_strdup(BGBROWN));
	else if (!ft_strcmp(abbr, "BGBLUE"))
		return (ft_strdup(BGBLUE));
	else if (!ft_strcmp(abbr, "BGMAGENTA"))
		return (ft_strdup(BGMAGENTA));
	else if (!ft_strcmp(abbr, "BGCYAN"))
		return (ft_strdup(BGCYAN));
	else if (!ft_strcmp(abbr, "BGGRAY"))
		return (ft_strdup(BGGRAY));
	else if (!ft_strcmp(abbr, "BGDEF"))
		return (ft_strdup(BGDEF));
	else
		return (NULL);
}

/*
** Gets corresponding to abbreviature (in curly braces) color code.
** Examples for abbreviature: RED, BLACK, MAGENTA etc.
**
** @param	block	abbreviature in curly braces.
**
** @return			color code.
*/

char		*get_color_code(const char *block)
{
	char *abbr;
	char *clr_val;
	char *tmp;

	clr_val = NULL;
	abbr = ft_strsub(block, 1, ft_strlen(block) - 2);
	if (abbr)
	{
		if ((tmp = search_in_options(abbr)))
			clr_val = tmp;
		else if ((tmp = search_in_text_colors(abbr)))
			clr_val = tmp;
		else if ((tmp = search_in_background_colors(abbr)))
			clr_val = tmp;
		ft_strdel(&abbr);
	}
	return (clr_val);
}
