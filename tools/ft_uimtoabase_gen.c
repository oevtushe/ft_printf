/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimtoabase_gen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:45:55 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:45:56 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

static int	val_len(uintmax_t val, unsigned int base, int sign)
{
	if (val < base && sign)
		return (2);
	else if (val < base)
		return (1);
	return (1 + val_len(val / base, base, sign));
}

static char	get_chr(uintmax_t val)
{
	if (val < 10)
		return (val + '0');
	return (val - 10 + 'a');
}

static void	ft_itoa_hlp(uintmax_t val, unsigned int base, char *res, int *idx)
{
	if (val < base)
		res[(*idx)++] = get_chr(val);
	else
	{
		ft_itoa_hlp(val / base, base, res, idx);
		res[(*idx)++] = get_chr(val % base);
	}
}

char		*ft_uimtoabase_gen(uintmax_t val, int sign, unsigned int base)
{
	char	*res;
	int		idx;

	idx = 0;
	res = NULL;
	if (base > 1 && base < 17)
	{
		res = ft_strnew(val_len(val, base, sign));
		if (res)
		{
			if (sign)
				res[idx++] = '-';
			ft_itoa_hlp(val, base, res, &idx);
		}
	}
	return (res);
}
