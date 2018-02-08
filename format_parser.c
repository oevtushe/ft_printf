#include "ft_printf_helpers.h"

static int	outside_param(const char *str, size_t *idx, void **data, int *di)
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
			val = *(int*)data[*di];
			ft_memdel(&data[*di]);
		}
	}
	else
	{
		val = *(int*)data[*di];
		ft_memdel(&data[(*di)++]);
	}
	return (val);
}

static int	get_width(const char *str, int *di, size_t *idx, void **data)
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
		width = outside_param(str, idx, data, di);
	}
	return (width);
}

/* def val = -1 in case this doesn't collapse with explicit set of precision */
static int	get_precision(const char *str, int *di, size_t *idx, void **data)
{
	int precision;

	precision = -1;
	if (str[(*idx)] == '.')
	{
		++(*idx);
		if (str[(*idx)] == '*')
		{
			++(*idx);
			precision = outside_param(str, idx, data, di);
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

static void		init_modifiers(const char *str, t_format *cf, size_t *idx)
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
	cf->modifier = mdf;
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

static void		init_default(t_format *cf)
{
	cf->width = -1;
	cf->precision = -1;
}

void		*get_cur_data(const char *str, size_t *idx, int *di, void **data)
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
	return (data[(*di)++]);
}

t_format	*format_parser(const char *str, int *di, void **data, int is_dlr)
{
	size_t		idx;
	t_format	*cur_format;

	idx = 1;
	cur_format = (t_format*)ft_memalloc(sizeof(t_format));
	init_default(cur_format);
	if (ft_strchr(ALL_TYPES, str[ft_strlen(str) - 1]) || str[1] == '%')
	{
		if (is_dlr && str[1] != '%')
			cur_format->data = get_cur_data(str, &idx, di, data);
		init_flags(str, cur_format, &idx);
		cur_format->width = get_width(str, di, &idx, data);
		cur_format->precision = get_precision(str, di, &idx, data);
		init_modifiers(str, cur_format, &idx);
		cur_format->type = str[idx];
		if (!is_dlr && str[1] != '%')
			cur_format->data = get_cur_data(str, &idx, di, data);
	}
	else
	{
		cur_format->data = ft_strdup(str);
		cur_format->type = T_UNDEF;
	}
	return (cur_format);
}
