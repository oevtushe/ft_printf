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
** Function checks type of logic for specifying index on data array.
*/

int	logic_type(t_list *extra)
{
	int		type;
	char	*str;

	type = 0;
	while (extra)
	{
		str = extra->content;
		if (str[1] != '%')
		{
			if (ft_strchr(str, '$'))
				type = 1;
			break ;
		}
		extra = extra->next;
	}
	return (type);
}
