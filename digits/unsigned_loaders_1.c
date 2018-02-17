#include "ft_printf_helpers.h"

void	load_llu(t_gdata *gdata, va_list ap)
{
	gdata->data.ulli = va_arg(ap, long long int);
	gdata->full_type->modifier = M_LL;
	gdata->full_type->type = T_UNSIGNED;
}

void	load_lu(t_gdata *gdata, va_list ap)
{
	gdata->data.uli = va_arg(ap, long int);
	gdata->full_type->modifier = M_L;
	gdata->full_type->type = T_UNSIGNED;
}

void	load_u(t_gdata *gdata, va_list ap)
{
	gdata->data.ui = va_arg(ap, unsigned int);
	gdata->full_type->modifier = M_DEFAULT;
	gdata->full_type->type = T_UNSIGNED;
}

void	load_ju(t_gdata *gdata, va_list ap)
{
	gdata->data.uim = va_arg(ap, uintmax_t);
	gdata->full_type->modifier = M_J;
	gdata->full_type->type = T_UNSIGNED;
}

void	load_zu(t_gdata *gdata, va_list ap)
{
	gdata->data.szi = va_arg(ap, size_t);
	gdata->full_type->modifier = M_Z;
	gdata->full_type->type = T_UNSIGNED;
}
