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
