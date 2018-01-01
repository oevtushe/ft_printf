#include "ft_printf.h"

char			*string_manager(t_format *format, const void *str)
{
	int		len;
	char	*res;

	len  = (int)ft_strlen(str);
	res = ft_strdup(str);
	if (format->precision >= 0 && format->precision < len)
		res = ft_strsub(res, 0, format->precision);
	if (format->width > len)
	{
		len = format->width;
		if (ft_strchr(format->flags, FLAG_MINUS))
			res = spc_string(&res, len, ' ', FLAG_MINUS);
		else
			res = spc_string(&res, len, ' ', 0);
	}
	/* modifiers */
	return (res);
}
