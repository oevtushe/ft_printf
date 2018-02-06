#include "ft_printf_helpers.h"

static void	data_index_rd(const char *str, size_t *idx)
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

static void	width_rd(const char *str, size_t *idx)
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
		data_index_rd(str, idx);
	}
}

static void	flags_rd(const char *str, size_t *idx)
{
	int i;

	i = *idx;
	while (str[i] == '+' || str[i] == '-' 
			|| str[i] == ' ' || str[i] == '0' ||
				str[i] == '#' || str[i] == '\'')
		++i;
	*idx = i;
}

static void	precision_rd(const char *str, size_t *idx)
{
	int i;

	i = *idx;
	if (str[i] == '.')
	{
		++i;
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
				++i;
			*idx = i;
		}
		else if (str[i] == '*')
		{
			*idx = ++i;
			data_index_rd(str, idx);
		}
	}
}

static void modifiers_rd(const char *str, size_t *idx)
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

char	*get_format_str(const char *str, size_t *idx)
{
	size_t	start;
	char	*res;

	res = NULL;
	start = (*idx)++;
	data_index_rd(str, idx);
	flags_rd(str, idx);
	width_rd(str, idx);
	precision_rd(str, idx);
	modifiers_rd(str, idx);
	if (str[*idx])
		++(*idx);
	res = ft_strsub(str, start, *idx - start);
	return (res);
}