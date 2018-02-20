/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:42:55 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:48:07 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_tools.h"

void	*ft_memjoin(void *p1, size_t sp1, void *p2, size_t sp2)
{
	unsigned char *res;

	res = (unsigned char *)malloc(sizeof(unsigned char) * (sp1 + sp2));
	if (res)
	{
		ft_memcpy(res, p1, sp1);
		ft_memcpy(res + sp1, p2, sp2);
	}
	return (res);
}
