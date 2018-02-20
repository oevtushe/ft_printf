/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:14 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:33:04 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Min len of format string is 2, no bug here
** full_type->type = str[len - 1] - is valid because we already
** checked type validness in get_type_arr
** Here type 'D' and type 'ld' has differences
*/

static t_ftype		*get_type(const char *str, size_t len)
{
	t_ftype *full_type;

	full_type = (t_ftype *)ft_memalloc(sizeof(t_ftype));
	if (str[len - 2] == 'l' && str[len - 3] == 'l')
		full_type->modifier = M_LL;
	else if (str[len - 2] == 'h' && str[len - 3] == 'h')
		full_type->modifier = M_HH;
	else if (str[len - 2] == 'l')
		full_type->modifier = M_L;
	else if (str[len - 2] == 'h')
		full_type->modifier = M_H;
	else if (str[len - 2] == 'z')
		full_type->modifier = M_Z;
	else if (str[len - 2] == 'j')
		full_type->modifier = M_J;
	else
		full_type->modifier = M_DEFAULT;
	full_type->type = str[len - 1];
	normalize_full_type(full_type);
	return (full_type);
}

static void			read_strtd(char *str, size_t len, t_ftype **ta, int *ti)
{
	int		i;
	char	*pos;

	i = 0;
	if (!ft_strchr(&str[i], '$'))
	{
		while ((pos = ft_strchr(&str[i], '*')))
		{
			i = pos - str + 1;
			ta[(*ti)++] = new_full_type(T_DEC, M_DEFAULT);
		}
		ta[(*ti)++] = get_type(str, len);
		return ;
	}
	while ((pos = ft_strchr(&str[i], '$')))
	{
		i = pos-- - str + 1;
		while (ft_isdigit(*pos))
			--pos;
		*ti = ft_atoi(pos + 1) - 1;
		if (*pos == '%' && !ta[*ti])
			ta[*ti] = get_type(str, len);
		else if (*pos == '*' && !ta[*ti])
			ta[*ti] = new_full_type(T_DEC, M_DEFAULT);
	}
}

/*
** Here we check if type is valid, if doesn't then we ignore it
*/

static t_ftype		**get_type_arr(t_list *extra, int arr_sz)
{
	size_t		len;
	char		*str;
	t_ftype		**type_arr;
	int			ta_idx;

	ta_idx = 0;
	type_arr = (t_ftype **)ft_memalloc(sizeof(t_ftype *) * (arr_sz + 1));
	while (extra)
	{
		str = (char *)extra->content;
		len = ft_strlen(str);
		if (ft_strchr(ALL_TYPES, str[len - 1]))
			read_strtd(str, len, type_arr, &ta_idx);
		extra = extra->next;
	}
	return (type_arr);
}

static void			*get_data(t_ftype *cur_type, va_list ap)
{
	t_gdata	*gdata;

	gdata = (t_gdata *)ft_memalloc(sizeof(t_gdata));
	gdata->full_type = cur_type;
	if (cur_type->type == T_DEC)
		signed_decimal_modifiers(cur_type, ap, gdata);
	else if (cur_type->type == T_UNSIGNED || cur_type->type == T_OCT
			|| cur_type->type == T_HEX ||
			cur_type->type == T_BHEX || cur_type->type == T_LUNSIGNED
			|| cur_type->type == T_BOCT)
		unsigned_decimal_modifiers(cur_type, ap, gdata);
	else if (cur_type->type == T_STR)
		str_modifiers(cur_type, ap, gdata);
	else if (cur_type->type == T_CHR)
		chr_modifiers(cur_type, ap, gdata);
	else if (cur_type->type == T_PTR)
		gdata->data.pv = va_arg(ap, void *);
	return (gdata);
}

t_gdata				**get_data_arr(t_list *extra, va_list ap)
{
	t_gdata		**gdata;
	t_ftype		**type_arr;
	int			idx;

	idx = get_arr_size(extra);
	gdata = (t_gdata **)ft_memalloc(sizeof(t_gdata *) * (idx + 1));
	type_arr = get_type_arr(extra, idx);
	idx = -1;
	while (type_arr[++idx])
		gdata[idx] = get_data(type_arr[idx], ap);
	free(type_arr);
	return (gdata);
}
