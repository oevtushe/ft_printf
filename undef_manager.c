/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undef_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:49:06 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:49:07 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

char	*undef_manager(t_format *sfmt, size_t *fmt_len)
{
	char *rs;

	rs = sfmt->gdata->data.pc;
	*fmt_len = ft_strlen(rs);
	ft_memdel((void**)&sfmt->gdata->full_type);
	ft_memdel((void **)&(sfmt->gdata));
	return (rs);
}
