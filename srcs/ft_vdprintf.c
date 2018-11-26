/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:07:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/26 17:08:16 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	size_t	sz;
	char	*res;

	sz = 0;
	if (format)
	{
		res = mk_format(format, ap, &sz);
		ft_putstr_fd(res, fd);
		free(res);
	}
	return (sz);
}
