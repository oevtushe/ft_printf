/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:43:07 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:43:08 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

/*
** Reallocates string with a new size.
** If new size is biggest than previous one, rest of reallocated string will
** be filled by zeroes.
** If new size is smaller than previous, string will be truncated.
** If allocation fails nothing to be done with string.
**
** @param	str		pointer to string to be reallocated.
** @param	new_len	length of result string.
*/

void	ft_str_realloc(char **str, size_t new_len)
{
	char	*new_str;

	if (str && *str)
	{
		new_str = ft_strnew(new_len);
		if (new_str)
		{
			ft_strncpy(new_str, *str, new_len);
			ft_strdel(str);
			*str = new_str;
		}
	}
}
