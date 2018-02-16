#include "ft_printf_helpers.h"

static void	read_data_index(const char *str, size_t *idx)
{
	int i;

	i = *idx;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			++i;
		if (str[i] == '$')
			*idx = ++i;
	}
}

static void	read_width(const char *str, size_t *idx)
{
	int i;

	i = *idx;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			++i;
		*idx = i;
	}
	else if (str[i] == '*')
	{
		*idx = ++i;
		read_data_index(str, idx);
	}
}

static void	read_flags(const char *str, size_t *idx)
{
	int i;

	i = *idx;
	while (str[i] == '+' || str[i] == '-' 
			|| str[i] == ' ' || str[i] == '0' ||
				str[i] == '#' || str[i] == '\'')
		++i;
	*idx = i;
}

static void	read_precision(const char *str, size_t *idx)
{
	if (str[*idx] == '.')
	{
		++(*idx);
		if (ft_isdigit(str[*idx]))
			while (ft_isdigit(str[*idx]))
				++(*idx);
		else if (str[*idx] == '*')
		{
			++(*idx);
			read_data_index(str, idx);
		}
	}
}

static void read_modifiers(const char *str, size_t *idx)
{
	if (str[*idx] == 'l' && str[*idx + 1] == 'l')
		*idx += 2;
	else if (str[*idx] == 'l')
		*idx += 1;
	else if (str[*idx] == 'h' && str[*idx + 1] == 'h')
		*idx += 2;
	else if (str[*idx] == 'h')
		*idx += 1;
	else if (str[*idx] == 'j')
		*idx += 1;
	else if (str[*idx] == 'z')
		*idx += 1;
}

char	*get_format_string(const char *str, size_t *idx)
{
	size_t	start;
	char	*res;

	res = NULL;
	start = (*idx)++;
	read_data_index(str, idx);
	read_flags(str, idx);
	read_width(str, idx);
	read_precision(str, idx);
	read_modifiers(str, idx);
	if (str[*idx])
		++(*idx);
	res = ft_strsub(str, start, *idx - start);
	return (res);
}
