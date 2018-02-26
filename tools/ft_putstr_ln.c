/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ln.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:43:01 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:43:02 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

/*
** String printer. Prints exactly @param len characters.
**
** @param	str		string to be printed.
** @param	cnt		count of character to be printed.
*/

void	ft_putstr_ln(const char *str, size_t cnt)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (i < cnt)
			write(1, &str[i++], 1);
	}
}
