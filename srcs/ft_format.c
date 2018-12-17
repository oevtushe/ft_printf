/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:22:19 by oevtushe          #+#    #+#             */
/*   Updated: 2018/12/17 16:07:04 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Function works like ft_printf, except printing
** string in the end it returns it.
**
** @param	len		placeholder for future string
**					length.
** @param	format	format of future string.
*/

char	*ft_format(const char *format, size_t *len, ...)
{
	va_list ap;
	char	*str;
	size_t	ln;

	str = NULL;
	if (!len)
		len = &ln;
	if (format && len)
	{
		*len = 0;
		va_start(ap, len);
		str = mk_format(format, ap, len);
		va_end(ap);
	}
	return (str);
}
