/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:00 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:48:01 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_helpers.h"
#include <stdarg.h>

int		ft_printf(const char *format, ...)
{
	size_t	len;
	va_list ap;
	char	*str;

	len = 0;
	va_start(ap, format);
	str = ft_format(format, ap, &len);
	ft_putstr_ln(str, len);
	va_end(ap);
	free(str);
	return (len);
}
