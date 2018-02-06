#include "ft_printf_helpers.h"

void		*str_modifiers(char *type, va_list ap)
{
	if (type[0] == 'l')
		return (va_arg(ap, wchar_t *));
	else
		return (va_arg(ap, char *));
}

static void	str_truncate(char **str, int new_len)
{
	char *new_str;

	new_str = ft_strnew(new_len);
	ft_memcpy(new_str, *str, new_len);
	free(*str);
	*str = new_str;
}

size_t		ft_wcslen(wchar_t *wcs)
{
	size_t i;

	i = 0;
	while (wcs[i])
		++i;
	return (i);
}

/* sfmt->precision >= 0 like in man (str may not have term. zero) */
char		*str_manager(t_format *sfmt)
{
	int		len;
	char	*res;

	res = ft_strdup(sfmt->data);
	len = ft_strlen(res);
	sfmt->data = NULL;
	if (sfmt->precision >= 0)
	{
		str_truncate(&res, sfmt->precision);
		len = sfmt->precision;
	}
	if (sfmt->width > len && sfmt->FLAG_MINUS)
		res = spc_string(&res, sfmt->width, ' ', '-');
	else if (sfmt->width > len)
		res = spc_string(&res, sfmt->width, ' ', 0);
	return (res);
}
