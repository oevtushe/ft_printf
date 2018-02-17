#include "ft_printf_helpers.h"

void ptr_modifiers(va_list ap, t_gdata *gdata)
{
	gdata->data.pv = va_arg(ap, void *);
	gdata->full_type->type = T_PTR;
}
