/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:40:13 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/26 16:47:52 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

int		ft_dprintf(int fd, const char *format, ...)
{
	size_t	sz;
	va_list ap;
	char	*res;

	sz = 0;
	if (format)
	{
		va_start(ap, format);
		res = mk_format(format, ap, &sz);
		ft_putstr_fd(res, fd);
		va_end(ap);
		free(res);
	}
	return (sz);
}
