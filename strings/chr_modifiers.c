#include "ft_printf_helpers.h"

static void		load_wi(t_gdata *gdata, va_list ap)
{
	gdata->data.wi = va_arg(ap, wint_t);
	gdata->type = T_CHR;
	gdata->modifier = M_L;
}

static void		load_d(t_gdata *gdata, va_list ap)
{
	gdata->data.c = va_arg(ap, int);
	gdata->type = T_CHR;
}

t_gdata			*chr_modifiers(char *type, va_list ap)
{
	t_gdata *gdata;

	gdata = (t_gdata *)ft_memalloc(sizeof(t_gdata));
	if (type[0] == 'l' || type[0] == T_WCHR)
		load_wi(gdata, ap);
	else
		load_d(gdata, ap);
	return (gdata);
}
