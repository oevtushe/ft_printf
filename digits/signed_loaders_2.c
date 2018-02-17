#include "ft_printf_helpers.h"

void	load_ld(t_gdata *gdata, va_list ap)
{
	gdata->data.li = va_arg(ap, long int);
	gdata->full_type->type = T_DEC;
	gdata->full_type->modifier = M_L;
}

void	load_lld(t_gdata *gdata, va_list ap)
{
	gdata->data.lli = va_arg(ap, long long int);
	gdata->full_type->type = T_DEC;
	gdata->full_type->modifier = M_LL;
}
