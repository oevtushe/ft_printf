#include "ft_printf_helpers.h"

void	read_data_index(const char *str, size_t *idx)
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

void	read_width(const char *str, size_t *idx)
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

void	read_flags(const char *str, size_t *idx)
{
	int i;

	i = *idx;
	while (str[i] == '+' || str[i] == '-' 
			|| str[i] == ' ' || str[i] == '0' ||
				str[i] == '#' || str[i] == '\'')
		++i;
	*idx = i;
}

void	read_precision(const char *str, size_t *idx)
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

void read_modifiers(const char *str, size_t *idx)
{
	if ((str[*idx] == 'l' && str[*idx + 1] == 'l') ||
			(str[*idx] == 'h' && str[*idx + 1] == 'h'))
		*idx += 2;
	else if (str[*idx] == 'z' || str[*idx] == 'j' ||
				(str[*idx] == 'h') || (str[*idx] == 'l'))
		*idx += 1;
}

void read_type(const char *str, size_t *idx)
{
	if (ft_strchr(ALL_TYPES, str[*idx]))
		(*idx)++;
}
