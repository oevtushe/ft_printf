#include "ft_printf.h"

static char		*get_flags(const char *str, char *all_flags, size_t *idx)
{
	char *flags;

	flags = ft_strnew(0);
	while (ft_strchr(all_flags, str[++(*idx)]))
		if (!flags || !ft_strchr(flags, str[(*idx)]))
			ft_strappend(&flags, str[(*idx)]);
	return (flags);
}

static int		get_width(const char *str, size_t *idx)
{
	size_t width;

	width = 0;
	if (ft_isdigit(str[(*idx)]))
	{
		width = (size_t)ft_atoi(&(str[(*idx)]));
		while (ft_isdigit(str[(*idx)]))
			++(*idx);
	}
	return (width);
}

static int	get_precision(const char *str, size_t *idx)
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
	return (precision);
}

static char	*get_modifier(const char *str, char **all_modifiers, size_t *idx)
{
	int		i;
	int		j;
	int		k;
	char	*modifier;

	i = -1;
	modifier = NULL;
	while (all_modifiers[++i])
	{
		j = *idx;
		k = -1;
		while (str[j] == all_modifiers[i][++k])
			++j;
		if (ft_strlen(all_modifiers[i]) == (size_t)k)
		{
			modifier = ft_strdup(all_modifiers[i]);
			*idx = j;
			break ;
		}
	}
	return (modifier);
}

t_format	*format_parser(const char *str, t_defaults *defaults, size_t *idx)
{
	t_format	*cur_format;

	cur_format = (t_format*)malloc(sizeof(t_format));
	cur_format->flags = get_flags(str, defaults->all_flags, idx);
	cur_format->width = get_width(str, idx);
	cur_format->precision = get_precision(str, idx);
	cur_format->modifier = get_modifier(str, defaults->all_modifiers, idx);
	if (ft_strchr(defaults->all_types, str[(*idx)]))
		cur_format->type = str[(*idx)];
	else
	{
		if (cur_format->flags)
			free(cur_format->flags);
		if (cur_format->modifier)
			free(cur_format->modifier);
		free(cur_format);
	}
	return (cur_format);
}
