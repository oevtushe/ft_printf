#include "ft_printf_helpers.h"

void		load_s(t_gdata *gdata, va_list ap)
{
	gdata->data.pc = va_arg(ap, char *);
	gdata->type = T_STR;
	gdata->modifier = M_DEFAULT;
}

void		load_ws(t_gdata *gdata, va_list ap)
{
	gdata->data.pwc = va_arg(ap, wchar_t *);
	gdata->type = T_STR;
	gdata->modifier = M_L;
}

t_gdata		*str_modifiers(char *type, va_list ap)
{
	t_gdata *gdata;

	gdata = (t_gdata *)malloc(sizeof(t_gdata));
	if (type[0] == 'l' || type[0] == T_WSTR)
		load_ws(gdata, ap);
	else
		load_s(gdata, ap);
	return (gdata);
}
