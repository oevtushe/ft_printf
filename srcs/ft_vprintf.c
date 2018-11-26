/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:51:57 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/26 16:58:42 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

int		ft_vprintf(const char *format, va_list ap)
{
	size_t	sz;
	char	*res;

	sz = 0;
	if (format)
	{
		res = mk_format(format, ap, &sz);
		ft_putstr(res);
		free(res);
	}
	return (sz);
}
