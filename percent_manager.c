/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:48:36 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

char	*percent_manager(t_format *sfmt, size_t *len)
{
	char *p;

	p = ft_strnew(1);
	p[0] = '%';
	*len = 1;
	ft_memdel((void **)&(sfmt->gdata));
	return (p);
}
