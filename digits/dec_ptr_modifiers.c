#include "ft_printf_helpers.h"

DATA_LOADER(void *, n)

void			*dec_ptr_modifiers(va_list ap)
{
	return (*(void**)load_n(ap));
}
