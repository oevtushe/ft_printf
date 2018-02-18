/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memconnect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:02:22 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 17:02:23 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

void	ft_memconnect(void **p1, size_t sp1, void *p2, size_t sp2)
{
	void *tmp;

	tmp = ft_memjoin(*p1, sp1, p2, sp2);
	ft_memdel(p1);
	*p1 = tmp;
}
