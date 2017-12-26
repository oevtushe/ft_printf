#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

#define	FLAG_PLUS '+'
#define	FLAG_MINUS '-'
#define	FLAG_ZERO '0'
#define	FLAG_SPACE ' '

#define TYPE_STRING 's'
#define TYPE_DECIMAL 'd'
#define TYPE_FLOAT 'f'

#define MODIFIER_h "h"
#define MODIFIER_hh "hh"
#define MODIFIER_l "l"
#define MODIFIER_ll "ll"
#define MODIFIER_L "L"

typedef	struct	s_format
{
	char	*flags;
	int		width;
	int		precision;
	char	*modifier;
	char	type;
}				t_format;

typedef struct	s_dafaults
{
	char	*all_flags;
	char	*all_types;
	char	**all_modifiers;
}				t_defaults;

char	*init_flags(void)
{
	char *res;

	res = ft_strnew(4);
	res[0] = FLAG_PLUS;
	res[1] = FLAG_MINUS;
	res[2] = FLAG_ZERO;
	res[3] = FLAG_SPACE;
	return (res);
}

char	*init_types(void)
{
	char *res;

	res = ft_strnew(3);
	res[0] = TYPE_STRING;
	res[1] = TYPE_DECIMAL;
	res[2] = TYPE_FLOAT;
	return (res);
}

char	**init_modifiers(void)
{
	char **res;

	res = (char**)malloc(sizeof(char*) * 6);
	res[0] = ft_strdup(MODIFIER_hh);
	res[1] = ft_strdup(MODIFIER_ll);
	res[2] = ft_strdup(MODIFIER_h);
	res[3] = ft_strdup(MODIFIER_l);
	res[4] = ft_strdup(MODIFIER_L);
	res[5] = NULL;
	return (res);
}

t_defaults	*init_defaults(void)
{
	t_defaults	*res;
	char		*all_flags;
	char		*all_types;
	char		**all_modifiers;

	all_flags = init_flags();
	all_types = init_types();
	all_modifiers = init_modifiers();
	res = (t_defaults*)malloc(sizeof(t_defaults));
	res->all_flags = all_flags;
	res->all_types = all_types;
	res->all_modifiers = all_modifiers;
	return (res);
}

void	ft_strappend(char **str, char c)
{
	size_t	len;
	char	*res;

	res = NULL;
	len = (*str) ? ft_strlen(*str) : 0;
	res = ft_strnew(len + 1);
	if (*str)
		ft_strcpy(res, *str);
	res[len] = c;
	if (*str)
		free(*str);
	*str = res;
}

char	*get_flags(char *str, char *all_flags, size_t *idx)
{
	char *flags;

	flags = NULL;
	while (ft_strchr(all_flags, str[++(*idx)]))
		if (!flags || !ft_strchr(flags, str[(*idx)]))
			ft_strappend(&flags, str[(*idx)]);
	return (flags);
}

int		get_width(char *str, size_t *idx)
{
	int width;

	width = 0;
	if (ft_isdigit(str[(*idx)]))
	{
		width = ft_atoi(&(str[(*idx)]));
		while (ft_isdigit(str[(*idx)]))
			++(*idx);
	}
	return (width);
}

int		get_precision(char *str, size_t *idx)
{
	int precision;

	precision = 0;
	if (str[(*idx)] == '.')
	{
		++(*idx);
		precision = ft_atoi(&(str[(*idx)]));
		while (ft_isdigit(str[(*idx)]))
			++(*idx);
	}
	return (precision);
}

char	*get_modifier(char *str, char **all_modifiers, size_t *idx)
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

/* %+6.3sstring */
t_format	*format_parser(char *str, t_defaults *defaults, size_t *idx)
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

void	free_format(t_format **format)
{
	free((*format)->flags);
	free(*format);
}

void	split_str(char *str, t_list **plain, t_list **format)
{
	size_t		prev;
	size_t		pos;
	char		*tmp;
	char		*sub;
	t_defaults	*defaults;
	t_list		*new_elem;
	t_format	*new_format;
	prev = 0;
	defaults = init_defaults();
	while ((tmp = ft_strchr(&(str[prev]), '%')))
	{
		pos = tmp - str;
		sub = ft_strsub(str, prev, pos - prev);
		new_elem = ft_lstnew(sub, ft_strlen(sub) + 1);
		free(sub);
		ft_lstappend(plain, new_elem);
		new_format = format_parser(str, defaults, &pos);
		new_elem = ft_lstnew(new_format, sizeof(t_format));
		free_format(&new_format);
		ft_lstappend(format, new_elem);
		prev = pos + 1;
	}
	if (prev != ft_strlen(str))
	{
		sub = ft_strsub(str, prev, ft_strlen(str) - prev);
		new_elem = ft_lstnew(sub, ft_strlen(sub) + 1);
		free(sub);
		ft_lstappend(plain, new_elem);
	}
}

int		main(void)
{
	char str[] = "%+0-6.4lldsome str";
	t_list	*plain;
	t_list	*format;

	plain = NULL;
	format = NULL;
	split_str(str, &plain, &format);
	return (0);
}
