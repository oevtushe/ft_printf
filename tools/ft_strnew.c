/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:43:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:43:30 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"
#include <stdlib.h>

char	*ft_strnew(const size_t len)
{
	size_t	i;
	char	*str;
	size_t	nl;

	nl = len + 1;
	if (!nl)
		return (NULL);
	i = 0;
	str = (char*)malloc(nl);
	if (!str)
		return (NULL);
	while (i < nl)
		str[i++] = 0;
	return (str);
}
