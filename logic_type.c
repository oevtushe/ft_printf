/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:36:00 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:36:07 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** For '*'
*/

int	logic_type(const char *str)
{
	int type;

	if (ft_strchr(str, '$'))
		type = 1;
	else
		type = 0;
	return (type);
}
