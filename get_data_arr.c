#include "ft_printf_helpers.h"

/*
** Min len of format string is 2, no bug here
*/

static char	*get_type(const char *str, size_t len)
{
	char *type;

	type = NULL;
	if ((str[len - 2] == 'l' && str[len - 3] == 'l') || 
			(str[len - 2] == 'h' && str[len - 3] == 'h'))
		type = ft_strsub(str, len - 3, 3);
	else if (str[len - 2] == 'l' || str[len - 2] == 'h' ||
				str[len - 2] == 'z' || str[len - 2] == 'j')
		type = ft_strsub(str, len - 2, 2);
	else
		type = ft_strsub(str, len - 1, 1);
	return (type);
}

static void	read_str_type_data(const char *str, size_t len, char **type_arr, int *ta_idx)
{
	int		i;
	char	*pos;

	i = 0;
	if (!ft_strchr(&str[i], '$'))
	{
		while ((pos = ft_strchr(&str[i], '*')))
		{
			i = pos - str + 1;
			type_arr[(*ta_idx)++] = ft_strdup("d");
		}
		type_arr[(*ta_idx)++] = get_type(str, len);
		return ;
	}
	while ((pos = ft_strchr(&str[i], '$')))
	{
		i = pos-- - str + 1;
		while (ft_isdigit(*pos))
			--pos;
		*ta_idx = ft_atoi(pos + 1) - 1;
		if (*pos == '%')
			type_arr[*ta_idx] = get_type(str, len);
		else if (*pos == '*')
			type_arr[*ta_idx] = ft_strdup("d");
	}
}

static char	**get_type_arr(t_list *extra, int	arr_sz)
{
	size_t	len;
	char	*str;
	char	**type_arr;
	int		ta_idx;

	ta_idx = 0;
	type_arr = (char **)ft_memalloc(sizeof(char *) * (arr_sz + 1));
	while (extra)
	{
		str = (char *)extra->content;
		len = ft_strlen(str);
		if (ft_strchr(ALL_TYPES, str[len - 1]))
			read_str_type_data(str, len, type_arr, &ta_idx);
		extra = extra->next;
	}
	return (type_arr);
}

void	**get_data_arr(t_list *extra, va_list ap)
{
	int		len;
	void	**data;
	int		dta_i;
	char	**type_arr;
	int		ta_idx;

	dta_i = get_arr_size(extra);
	data = (void **)ft_memalloc(sizeof(void *) * (dta_i + 1));
	type_arr = get_type_arr(extra, dta_i);
	dta_i = 0;
	ta_idx = -1;
	while (type_arr[++ta_idx])
	{
		len = ft_strlen(type_arr[ta_idx]);
		if (type_arr[ta_idx][len - 1] == 'd')
			data[dta_i++] = signed_decimal_modifiers(type_arr[ta_idx], ap);
		else if (type_arr[ta_idx][len - 1] == 'u')
			data[dta_i++] = unsigned_decimal_modifiers(type_arr[ta_idx], ap);
		else if (type_arr[ta_idx][len - 1] == 'n')
			data[dta_i++] = dec_ptr_modifiers(ap);
		else if (type_arr[ta_idx][len - 1] == 's')
			data[dta_i++] = str_modifiers(type_arr[ta_idx], ap);
		else if (type_arr[ta_idx][len - 1] == 'c')
			data[dta_i++] = chr_modifiers(type_arr[ta_idx], ap);
	}
	void_ptr_arr_del((void***)&type_arr);
	return (data);
}
