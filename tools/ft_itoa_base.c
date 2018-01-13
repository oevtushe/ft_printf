/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:17:59 by oevtushe          #+#    #+#             */
/*   Updated: 2018/01/13 13:18:01 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_itoa_base(intmax_t val, int base)
{
	int			sign;
	uintmax_t	uval;

	sign = 0;
	if (val < 0)
	{
		uval = val * -1L;
		sign = 1;
	}
	else
		uval = val;
	return (ft_uitoa_base_gen(val, sign, base));
}
