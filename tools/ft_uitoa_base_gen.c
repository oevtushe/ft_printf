/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base_gen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:12:31 by oevtushe          #+#    #+#             */
/*   Updated: 2018/01/13 17:03:40 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <inttypes.h>

static int	val_len(uintmax_t val)
{
	if (val < 10)
		return (1);
	return (1 + val_len(val / 10));
}

static char	get_chr(uintmax_t val)
{
	if (val < 10)
		return (val + '0');
	return (val - 10 + 'a');
}

static void	ft_itoa_hlp(uintmax_t val, int base, char *res, int *idx)
{
	if (val < (uintmax_t)base)
		res[(*idx)++] = get_chr(val);
	else
	{
		ft_itoa_hlp(val / base, base, res, idx);
		res[(*idx)++] = get_chr(val % base);
	}
}

char	*ft_uitoa_base_gen(uintmax_t val, int sign, int base)
{
	char	*res;
	int		idx;

	idx = 0;
	res = NULL;
	if (base > 1 && base < 17)
	{
		if (sign)
		{
			res = ft_strnew(val_len(val) + 1);
			res[idx++] = '-';
		}
		else
			res = ft_strnew(val_len(val));
		ft_itoa_hlp(val, base, res, &idx);
	}
	return (res);
}
