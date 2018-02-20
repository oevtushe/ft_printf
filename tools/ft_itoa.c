/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:42:20 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:48:42 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

char			*ft_itoa(const int n)
{
	int				sign;
	unsigned int	nn;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		nn = n * -1L;
	}
	else
		nn = n;
	return (ft_uimtoa_hlp(nn, sign));
}
