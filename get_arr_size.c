/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arr_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:11 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:48:12 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

static int	get_max_idx_dl(const char *str)
{
	size_t	i;
	int		cur_max;
	int		tmp;
	char	*pos;

	i = 1;
	cur_max = read_data_index(str, &i);
	while ((pos = ft_strchr(&str[i], '*')))
	{
		i = pos - str;
		++i;
		tmp = read_data_index(str, &i);
		cur_max = (tmp > cur_max) ? tmp : cur_max;
	}
	return (cur_max);
}

static int	get_max_idx_smp(const char *str)
{
	char	*pos;
	int		idx;
	int		prev;

	idx = 1;
	prev = 0;
	while ((pos = ft_strchr(&str[prev], '*')))
	{
		++idx;
		prev = pos - str + 1;
	}
	return (idx);
}

int			get_arr_size(t_list *extra)
{
	char	*cur;
	int		tmp;
	int		max;

	tmp = 0;
	max = 0;
	while (extra)
	{
		cur = (char*)extra->content;
		if (cur[1] != '%')
		{
			tmp = get_max_idx_dl(cur);
			if (tmp == -1)
			{
				tmp = get_max_idx_smp(cur);
				max += tmp;
			}
			else
				max = (tmp > max) ? tmp : max;
		}
		extra = extra->next;
	}
	return (max);
}
