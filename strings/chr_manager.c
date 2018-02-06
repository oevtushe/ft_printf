#include "ft_printf_helpers.h"

char	*chr_manager(t_format *sfmt)
{
	char	*res;

	if (sfmt->modifier == M_L)
		res = ft_witomb(unicode_to_utf8(*(wint_t *)sfmt->data));
	else
	{
		res = ft_strnew(1);
		res[0] = ((char *)sfmt->data)[0];
	}
	align(&res, sfmt);
	return (res);
}
