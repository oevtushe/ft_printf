/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:00 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/10 17:04:16 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		ft_printf(const char *format, ...)
{
	size_t	len;
	va_list ap;
	char	*str;
	char	*cp;

	len = 0;
	va_start(ap, format);
	str = ft_format(format, ap, &len);
	if (len == ft_strlen(str))
	{
		color_parser(str, &cp);
		ft_strdel(&str);
		str = cp;
		len = ft_strlen(str);
	}
	ft_putstr_ln(str, len);
	va_end(ap);
	ft_strdel(&str);
	return (len);
}
