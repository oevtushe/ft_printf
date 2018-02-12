#include "ft_printf_helpers.h"

static size_t	helper(char **res, t_format *sfmt)
{
	size_t len;

	if ((*res)[0] == '\0')
	{
		align(res, sfmt);
		len = ft_strlen(*res) + 1;
		if (sfmt->FLAG_MINUS)
			(*res)[0] = 0;
		else if (len > 1)
			(*res)[len-- - 2] = 0;
	}
	else
	{
		align(res, sfmt);
		len = ft_strlen(*res);
	}
	return (len);
}

char	*chr_manager(t_format *sfmt, size_t *len)
{
	char	*res;

	if (sfmt->modifier == M_L || sfmt->type == T_WCHR)
		res = ft_witomb(unicode_to_utf8(*(wint_t *)sfmt->data));
	else
	{
		res = ft_strnew(1);
		res[0] = ((char *)sfmt->data)[0];
	}
	*len = helper(&res, sfmt);
	return (res);
}
