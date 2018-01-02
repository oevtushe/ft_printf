#include "ft_printf_helpers.h"

void		init_width(const char *str, t_format *cf, size_t *idx)
{
	size_t width;

	width = 0;
	if (ft_isdigit(str[(*idx)]))
	{
		width = (size_t)ft_atoi(&(str[(*idx)]));
		while (ft_isdigit(str[(*idx)]))
			++(*idx);
	}
	cf->width = width;
}

void		init_precision(const char *str, t_format *cf, size_t *idx)
{
	int precision;

	precision = -1;
	if (str[(*idx)] == '.')
	{
		++(*idx);
		precision = ft_atoi(&(str[(*idx)]));
		while (ft_isdigit(str[(*idx)]))
			++(*idx);
	}
	cf->precision = precision;
}

void		init_modifiers(const char *str, t_format *cf, size_t *idx)
{
	if (str[*idx] == 'l' && str[*idx + 1] != 'l')
	{
		cf->MODIFIER_l = 1;
		++(*idx);
	}
	else if (str[*idx] == 'l' && str[*idx + 1] == 'l')
	{
		cf->MODIFIER_ll = 1;
		*idx += 2;
	}
	else if (str[*idx] == 'h' && str[*idx + 1] != 'h')
	{
		cf->MODIFIER_h = 1;
		++(*idx);
	}
	else if (str[*idx] == 'h' && str[*idx + 1] == 'h')
	{
		cf->MODIFIER_hh = 1;
		*idx += 2;
	}
}

void		init_flags(const char *str, t_format *cf, size_t *idx)
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
		else 
			break ;
		++(*idx);
	}
}

t_format	*format_parser(const char *str, const char *all_types, size_t *idx)
{
	t_format	*cur_format;

	++(*idx);
	cur_format = (t_format*)malloc(sizeof(t_format));
	init_flags(str, cur_format, idx);
	init_width(str, cur_format, idx);
	init_precision(str, cur_format, idx);
	init_modifiers(str, cur_format, idx);
	if (ft_strchr(all_types, str[(*idx)]))
		cur_format->type = str[(*idx)];
	else
	{
		free(cur_format);
		cur_format = NULL;
	}
	return (cur_format);
}
