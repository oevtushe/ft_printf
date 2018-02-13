#include "ft_printf_helpers.h"

t_gdata	*pos_modifiers(va_list ap)
{
	t_gdata *gdata;

	gdata = (t_gdata *)ft_memalloc(sizeof(t_gdata));
	gdata->data.pv = va_arg(ap, void *);
	gdata->type = T_PS;
	return (gdata);
}
