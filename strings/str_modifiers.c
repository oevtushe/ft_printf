#include "ft_printf_helpers.h"

void		load_s(t_gdata *gdata, va_list ap)
{
	gdata->data.pc = va_arg(ap, char *);
	gdata->full_type->type = T_STR;
	gdata->full_type->modifier = M_DEFAULT;
}

void		load_ws(t_gdata *gdata, va_list ap)
{
	gdata->data.pwc = va_arg(ap, wchar_t *);
	gdata->full_type->type = T_STR;
	gdata->full_type->modifier = M_L;
}

void	str_modifiers(char *type, va_list ap, t_gdata *gdata)
{
	if (type[0] == 'l' || type[0] == T_WSTR)
		load_ws(gdata, ap);
	else
		load_s(gdata, ap);
}
