/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:47:32 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:47:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

void	align(char **sv, t_format *sfmt)
{
	int		len;
	char	*res;

	res = ft_strdup(*sv);
	if (res)
	{
		len = ft_strlen(res);
		if (sfmt->width > len && sfmt->FLAG_MINUS)
			spc_string(&res, sfmt->width, ' ', '-');
		else if (sfmt->width > len)
			spc_string(&res, sfmt->width, ' ', 0);
		ft_strdel(sv);
		*sv = res;
	}
}
