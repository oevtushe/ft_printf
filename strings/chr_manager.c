#include "ft_printf_helpers.h"

DATA_LOADER(int, d)
DATA_LOADER(wint_t, wi)

void		*chr_modifiers(char *type, va_list ap)
{
	if (type[0] == 'l')
		return (load_wi(ap));
	else
		return (load_d(ap));
}

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
