/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:38:58 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:39:03 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

static size_t	helper(char **res, t_format *sfmt)
{
	size_t len;

	if ((*res)[0] == '\0')
	{
		align(res, sfmt);
		len = ft_strlen(*res) + 1;
		if (sfmt->FLAG_MINUS)
		{
			(*res)[0] = 0;
			len--;
		}
		else if (len > 1)
			(*res)[len-- - 2] = 0;
	}
	else
	{
		align(res, sfmt);
		len = ft_strlen(*res);
	}
	return (len);
}

void	print_memory(void *data, size_t size);
char	*chr_manager(t_format *sfmt, size_t *len)
{
	char	*res;

	if ((sfmt->gdata->full_type->modifier == M_L || sfmt->gdata->full_type->type == T_WCHR)
			&& MB_CUR_MAX > 1)
		res = ft_witomb(unicode_to_utf8(sfmt->gdata->data.wi));
	else
	{
		res = ft_strnew(1);
		res[0] = sfmt->gdata->data.c;
	}
	*len = helper(&res, sfmt);
	return (res);
}
