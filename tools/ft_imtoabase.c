/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:42:10 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:42:11 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

/*
** Converts signed number to specified base and write it to string.
**
** @param	val		value to be converted.
** @param	base	base value be converted to.
**
** @return			string with value in specified base.
*/

char	*ft_imtoabase(intmax_t val, unsigned int base)
{
	int			sign;
	uintmax_t	uval;

	sign = 0;
	if (val < 0)
	{
		uval = val * -1L;
		if (base == 10)
			sign = 1;
	}
	else
		uval = val;
	return (ft_uimtoabase_gen(uval, sign, base));
}
