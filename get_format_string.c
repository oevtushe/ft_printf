#include "ft_printf_helpers.h"

char	*get_format_string(const char *str, size_t *idx)
{
	size_t		start;
	char		*res;

	res = NULL;
	start = (*idx)++;
	read_data_index(str, idx);
	read_flags(str, idx);
	read_width(str, idx);
	read_precision(str, idx);
	read_modifiers(str, idx);
	read_type(str, idx);
	res = ft_strsub(str, start, *idx - start);
	return (res);
}
