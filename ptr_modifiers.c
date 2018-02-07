#include "ft_printf_helpers.h"

void	*ptr_modifiers(va_list ap)
{
	void *dta;

	dta = va_arg(ap, void *);
	return (dta);
}
