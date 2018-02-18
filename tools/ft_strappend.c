/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:43:12 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:43:13 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"
#include <stdlib.h>

void	ft_strappend(char **str, char c)
{
	size_t	len;
	char	*res;

	res = NULL;
	len = (*str) ? ft_strlen(*str) : 0;
	res = ft_strnew(len + 1);
	if (*str)
		ft_strcpy(res, *str);
	res[len] = c;
	if (*str)
		free(*str);
	*str = res;
}
