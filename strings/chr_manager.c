#include "ft_printf_helpers.h"

static void	printer(char **res, t_format *sfmt)
{
	size_t cnt;
	size_t len;

	cnt = 0;
	if ((*res)[0] == '\0')
	{
		align(res, sfmt);
		len = ft_strlen(*res);
		len = len ? len : 1;
		if (sfmt->FLAG_MINUS)
			(*res)[0] = 0;
		else if (len)
			(*res)[len - 1] = 0;
		while (cnt < len)
			write(1, &(*res)[cnt++], 1);
	}
	else
	{
		align(res, sfmt);
		ft_putstr(*res);
	}
}

char	*chr_manager(t_format *sfmt)
{
	char	*res;

	if (sfmt->modifier == M_L || sfmt->type == T_WCHR)
		res = ft_witomb(unicode_to_utf8(*(wint_t *)sfmt->data));
	else
	{
		res = ft_strnew(1);
		res[0] = ((char *)sfmt->data)[0];
	}
	printer(&res, sfmt);
	ft_str_realloc(&res, 0);
	return (res);
}
