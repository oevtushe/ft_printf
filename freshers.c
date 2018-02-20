/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freshers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:47:53 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:17:28 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

void	del_simple(void *data, size_t size)
{
	++size;
	if (data)
		free(data);
}

void	del_extra(void *data, size_t size)
{
	++size;
	if (data)
	{
		free(data);
	}
}

void	del_gdata_arr(t_gdata ***arr)
{
	int		i;
	t_gdata	*tmp;

	i = 0;
	tmp = (*arr)[i];
	while (tmp)
	{
		free_gdata(&tmp);
		tmp = (*arr)[++i];
	}
	free(*arr);
}

void	del_void_ptr_arr(void ***dta)
{
	int		i;
	void	*tmp;

	i = 0;
	tmp = (*dta)[i];
	while (tmp)
	{
		free(tmp);
		tmp = (*dta)[++i];
	}
	free(*dta);
}

void	free_gdata(t_gdata **gdata)
{
	ft_memdel((void **)&((*gdata)->full_type));
	ft_memdel((void **)gdata);
}
