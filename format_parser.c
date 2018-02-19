/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:47:49 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:47:50 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** function get data from @param gdata by index in @param str
*/

static int	outside_param(const char *str, size_t *idx, t_gdata **gdata, int *di)
{
	int val;

	val = -1;
	if (ft_isdigit(str[*idx]))
	{
		*di = ft_atoi(&str[*idx]) - 1;
		while (ft_isdigit(str[*idx]))
			++(*idx);
		if (str[*idx] == '$')
		{
			++(*idx);
			val = gdata[*di]->data.i;
		}
	}
	else
		val = gdata[(*di)++]->data.i;
	return (val);
}

/*
** function read width from @param str or from @param gdata if '$' present
*/

static int	get_width(const char *str, int *di, size_t *idx, t_gdata **gdata)
{
	size_t	width;

	width = 0;
	if (ft_isdigit(str[(*idx)]))
	{
		width = (size_t)ft_atoi(&(str[(*idx)]));
		while (ft_isdigit(str[(*idx)]))
			++(*idx);
	}
	else if (str[(*idx)] == '*')
	{
		++(*idx);
		width = outside_param(str, idx, gdata, di);
	}
	return (width);
}

/*
** function read precision from @param str or from @param gdata if '$' present
** def val = -1 in case this value doesn't collapse with none of explicit set
*/

static int	get_precision(const char *str, int *di, size_t *idx, t_gdata **gdata)
{
	int precision;

	precision = -1;
	if (str[(*idx)] == '.')
	{
		precision = 0;
		++(*idx);
		if (str[(*idx)] == '*')
		{
			++(*idx);
			precision = outside_param(str, idx, gdata, di);
		}
		else
		{
			precision = ft_atoi(&(str[(*idx)]));
			while (ft_isdigit(str[(*idx)]))
				++(*idx);
		}
	}
	return (precision);
}

static void		init_modifiers(const char *str, size_t *idx)
{
	int mdf;

	mdf = M_DEFAULT;
	if (str[*idx] == 'l' && str[*idx + 1] == 'l')
		mdf = M_LL;
	else if (str[*idx] == 'l')
		mdf = M_L;
	else if (str[*idx] == 'h' && str[*idx + 1] == 'h')
		mdf = M_HH;
	else if (str[*idx] == 'h')
		mdf = M_H;
	else if (str[*idx] == 'j')
		mdf = M_J;
	else if (str[*idx] == 'z')
		mdf = M_Z;
	if (mdf == M_HH || mdf == M_LL)
		*idx += 2;
	else if(mdf == M_L || mdf == M_H || mdf == M_J || mdf == M_Z)
		(*idx)++;
}

static void		init_flags(const char *str, t_format *cf, size_t *idx)
{
	while (str[*idx])
	{
		if (str[*idx] == '+')
			cf->FLAG_PLUS = 1;
		else if (str[*idx] == '-')
			cf->FLAG_MINUS = 1;
		else if (str[*idx] == ' ')
			cf->FLAG_SPACE = 1;
		else if (str[*idx] == '0')
			cf->FLAG_ZERO = 1;
		else if (str[*idx] == '#')
			cf->FLAG_SHARP = 1;
		else if (str[*idx] == '\'')
			cf->FLAG_SQUOTE = 1;
		else 
			break ;
		++(*idx);
	}
}

/*
** function return data from @param gdata arr by index readed from @param str
** in case of '$' appearence
** or by index @param di
*/

t_gdata			*get_cur_data(const char *str, size_t *idx, int *di, t_gdata **gdata)
{
	int j;
	int ndi;

	j = *idx;
	if (ft_isdigit(str[j]))
	{
		ndi = ft_atoi(&str[j]) - 1;
		while (ft_isdigit(str[j]))
			++j;
		if (str[j] == '$')
		{
			*di = ndi;
			*idx = ++j;
		}
	}
	return (gdata[(*di)++]);
}

/*
** In case of wrong format string
** function return copy of that one
*/

static void		spec_cases(const char *str, t_format *sfmt)
{
	t_gdata *gdata;

	gdata = (t_gdata *)ft_memalloc(sizeof(t_gdata));
	gdata->full_type = (t_full_type *)ft_memalloc(sizeof(t_full_type));
	if (str[1] == '%')
		gdata->full_type->type = T_PT;
	else
	{
		gdata->data.pc = ft_strdup(str);
		gdata->full_type->type = T_UNDEF;
		gdata->full_type->modifier = M_DEFAULT;
	}
	sfmt->gdata = gdata;
}

/*
** For '*'
*/

int				logic_type(const char *str)
{
	int type;

	if (ft_strchr(str, '$'))
		type = 1;
	type = 0;
	return (type);
}

void			normalize_width(t_format *sfmt)
{
	unsigned int width;

	if (sfmt->width < 0)
	{
		width = sfmt->width * -1;
		sfmt->FLAG_MINUS = 1;
	}
	else
		width = sfmt->width;
	sfmt->width = width;
}

/*
** format_parser initialise t_format structure by data
** explicit given in @param str or load it from @param gdata
** by index given in the string.
*/

t_format		*format_parser(const char *str, int *di, t_gdata **gdata)
{
	int			lt;
	size_t		idx;
	t_format	*cur_format;

	idx = 1;
	cur_format = (t_format*)ft_memalloc(sizeof(t_format));
	if (ft_strchr(ALL_TYPES, str[ft_strlen(str) - 1]))
	{
		lt = logic_type(str);
		if (lt)
			cur_format->gdata = get_cur_data(str, &idx, di, gdata);
		init_flags(str, cur_format, &idx);
		cur_format->width = get_width(str, di, &idx, gdata);
		cur_format->precision = get_precision(str, di, &idx, gdata);
		if (!lt)
			cur_format->gdata = get_cur_data(str, &idx, di, gdata);
		init_modifiers(str, &idx);
	}
	else
		spec_cases(str, cur_format);
	normalize_width(cur_format);
	return (cur_format);
}
