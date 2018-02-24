/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcs_to_utf8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:41:03 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:41:04 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

char		*wcs_to_utf8(wchar_t *wcs, int len)
{
	char			*res;
	char			*dp;
	wint_t			utf;
	int				sum_len;
	int				cnt;

	res = ft_strnew(0);
	sum_len = 0;
	cnt = -1;
	while ((sum_len < len || len < 0) && wcs[++cnt])
	{
		utf = unicode_to_utf8(wcs[cnt]);
		dp = ft_witomb(utf);
		sum_len += ft_strlen(dp);
		if (sum_len > len && len >= 0)
		{
			ft_strdel(&dp);
			break ;
		}
		ft_strconnect(&res, dp, 1);
		ft_strdel(&dp);
	}
	return (res);
}
