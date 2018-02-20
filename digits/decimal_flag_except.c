/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_flag_except.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:49:32 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:49:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

void	decimal_flag_except(t_format *sfmt, int negative)
{
	if (sfmt->flag_minus && sfmt->flag_zero)
		sfmt->flag_zero = 0;
	if (sfmt->precision >= 0 && sfmt->flag_zero)
		sfmt->flag_zero = 0;
	if (sfmt->flag_plus && sfmt->flag_space)
		sfmt->flag_space = 0;
	if (negative && sfmt->flag_plus)
		sfmt->flag_plus = 0;
	if (negative && sfmt->flag_space)
		sfmt->flag_space = 0;
}
