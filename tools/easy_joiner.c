/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_joiner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:41:54 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:41:57 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"
#include <stdlib.h>

char	*easy_joiner(char *str, char *fst, char *scd)
{
	char *tmp;
	char *res;

	res = ft_strjoin(str, fst);
	tmp = res;
	res = ft_strjoin(res, scd);
	ft_strdel(&tmp);
	return (res);
}
