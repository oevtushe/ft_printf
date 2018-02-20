/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_full_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:37:31 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:37:39 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** After this function no differences between type 'D' and type "ld"
*/

void	normalize_full_type(t_ftype *full_type)
{
	if (full_type->type == T_DEC2)
		full_type->type = T_DEC;
	else if (full_type->type == T_LDEC)
	{
		full_type->type = T_DEC;
		full_type->modifier = M_L;
	}
	else if (full_type->type == T_LUNSIGNED)
	{
		full_type->type = T_UNSIGNED;
		full_type->modifier = M_L;
	}
	else if (full_type->type == T_WCHR)
	{
		full_type->type = T_CHR;
		full_type->modifier = M_L;
	}
	else if (full_type->type == T_WSTR)
	{
		full_type->type = T_STR;
		full_type->modifier = M_L;
	}
}
