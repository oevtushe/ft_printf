#include "ft_printf_helpers.h"

static void		init_width(const char *str, t_format *cf, size_t *idx, va_list ap)
{
	size_t width;

	width = 0;
	if (ft_isdigit(str[(*idx)]))
	{
		width = (size_t)ft_atoi(&(str[(*idx)]));
		while (ft_isdigit(str[(*idx)]))
			++(*idx);
	}
	else if (str[(*idx)] == '*')
	{
		width = va_arg(ap, int);
		++(*idx);
	}
	cf->width = width;
}

static void		init_precision(const char *str, t_format *cf, size_t *idx, va_list ap)
{
	int precision;

	precision = -1;
	if (str[(*idx)] == '.')
	{
		++(*idx);
		if (str[(*idx)] == '*')
		{
			precision = va_arg(ap, int);
			++(*idx);
		}
		else
		{
			precision = ft_atoi(&(str[(*idx)]));
			while (ft_isdigit(str[(*idx)]))
				++(*idx);
		}
	}
	cf->precision = precision;
}

static void		init_modifiers(const char *str, t_format *cf, size_t *idx)
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
	else if (str[*idx] == 'j')
	{
		cf->MODIFIER_j = 1;
		++(*idx);
	}
	else if (str[*idx] == 'z')
	{
		cf->MODIFIER_z = 1;
		++(*idx);
	}
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
		else 
			break ;
		++(*idx);
	}
}

static void		init_default(t_format *cf)
{
	cf->MODIFIER_l = 0;
	cf->MODIFIER_ll = 0;
	cf->MODIFIER_h = 0;
	cf->MODIFIER_hh = 0;
	cf->MODIFIER_j = 0;
	cf->MODIFIER_z = 0;
	cf->FLAG_PLUS = 0;
	cf->FLAG_MINUS = 0;
	cf->FLAG_SPACE = 0;
	cf->FLAG_ZERO = 0;
	cf->width = -1;
	cf->precision = -1;
}

/*
   num$ 
   - could be after % or * 
   - if $ specified in single format, it should be specified in all conversations */
t_format	*format_parser(const char *str, const char *all_types, size_t *idx, va_list ap)
{
	t_format	*cur_format;

	++(*idx);
	cur_format = (t_format*)malloc(sizeof(t_format));
	init_default(cur_format);
	init_flags(str, cur_format, idx);
	init_width(str, cur_format, idx, ap);
	init_precision(str, cur_format, idx, ap);
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
