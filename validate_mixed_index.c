/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_mixed_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 17:39:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/20 17:39:59 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Another level of validation.
** For cases like "%3$.*d"
*/

int	validate_mixed_index(const char *str)
{
	char	*pos;

	if (ft_strchr(str, '$'))
		if ((pos = ft_strchr(str, '*')))
			if (!ft_isdigit(*(pos + 1)))
				return (0);
	return (1);
}
