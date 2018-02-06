#include "ft_printf_helpers.h"

void		*str_modifiers(char *type, va_list ap)
{
	if (type[0] == 'l')
		return (va_arg(ap, wchar_t *));
	else
		return (va_arg(ap, char *));
}
