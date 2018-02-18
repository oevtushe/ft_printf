/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:42:25 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:42:27 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

char			*ft_lltoa(const long long int n)
{
	int sign;
	unsigned long long int nn;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		nn = n * -1LL;
	}
	else
		nn = n;
	return (ft_uimtoa_hlp(nn, sign));
}
