/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:44:51 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/19 13:49:23 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_intln_help(unsigned long long int n)
{
	if (n <= 9)
		return (1);
	return (1 + ft_intln_help(n / 10));
}

static int		ft_intln(unsigned long long int n, int sign)
{
	int			extra;

	extra = 0;
	if (sign < 0)
		extra = 1;
	return (extra + ft_intln_help(n));
}

static void		ft_itoa_help(unsigned long long int n, char *str, int *idx)
{
	if (n <= 9)
	{
		str[(*idx)++] = n + '0';
		return ;
	}
	ft_itoa_help(n / 10, str, idx);
	str[(*idx)++] = (n % 10) + '0';
}

char			*ft_itoa(int n)
{
	char					*res;
	unsigned long long int	nn;
	int						idx;
	int						sgn;

	idx = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		nn = n * -1;
	}
	res = ft_strnew(ft_intln(nn, sign));
	if (res)
	{
		if (sign < 0)
			res[idx++] = '-';
		ft_itoa_help(nn, res, &idx);
	}
	return (res);
}
