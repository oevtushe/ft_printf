#include "ft_printf.h"

static char		*reformat_string(char *str, size_t new_len, char filler, char side)
{
	size_t	tjlen;
	char	*res;
	char	*to_join;

	tjlen = new_len - ft_strlen(str);
	to_join = ft_strnew(tjlen);
	ft_memset(to_join, filler, tjlen);
	if (side == '-')
		res = ft_strjoin(str, to_join);
	else
		res = ft_strjoin(to_join, str);
	return (res);
}

char			*string_manager(t_format *format, const void *str)
{
	int		len;
	char	*res;
	char	*tmp;

	len  = (int)ft_strlen(str);
	res = ft_strdup(str);
	if (format->precision >= 0 && format->precision < len)
	{
		res = ft_strsub(res, 0, format->precision);
	}
	if (format->width > len)
	{
		len = format->width;
		if (ft_strchr(format->flags, FLAG_MINUS))
		{
			tmp = res;
			res = reformat_string(res, len, ' ', FLAG_MINUS);
			ft_strdel(&tmp);
		}
		else
		{
			tmp = res;
			res = reformat_string(res, len, ' ', 0);
			ft_strdel(&tmp);
		}
	}
	/* modifiers */
	return (res);
}
