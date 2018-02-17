#include "ft_printf_helpers.h"

void	load_hu(t_gdata *gdata, va_list ap)
{
	gdata->data.usi = va_arg(ap, unsigned int);
	gdata->full_type->modifier = M_H;
	gdata->full_type->type = T_UNSIGNED;
}

void	load_hhu(t_gdata *gdata, va_list ap)
{
	gdata->data.uc = va_arg(ap, unsigned int);
	gdata->full_type->modifier = M_HH;
	gdata->full_type->type = T_UNSIGNED;
}
