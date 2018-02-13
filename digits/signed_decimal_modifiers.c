#include "ft_printf_helpers.h"

void	load_hhd(t_gdata *gdata, va_list ap)
{
	gdata->data.c = va_arg(ap, int);
	gdata->type = T_DEC;
	gdata->modifier = M_HH;
}

void	load_hd(t_gdata *gdata, va_list ap)
{
	gdata->data.si = va_arg(ap, int);
	gdata->type = T_DEC;
	gdata->modifier = M_H;
}

void	load_d(t_gdata *gdata, va_list ap)
{
	gdata->data.i = va_arg(ap, int);
	gdata->type = T_DEC;
	gdata->modifier = M_DEFAULT;
}

void	load_zd(t_gdata *gdata, va_list ap)
{
	gdata->data.sszi = va_arg(ap, ssize_t);
	gdata->type = T_DEC;
	gdata->modifier = M_Z;
}

void	load_jd(t_gdata *gdata, va_list ap)
{
	gdata->data.im = va_arg(ap, intmax_t);
	gdata->type = T_DEC;
	gdata->modifier = M_J;
}

void	load_ld(t_gdata *gdata, va_list ap)
{
	gdata->data.li = va_arg(ap, long int);
	gdata->type = T_DEC;
	gdata->modifier = M_L;
}

void	load_lld(t_gdata *gdata, va_list ap)
{
	gdata->data.lli = va_arg(ap, long long int);
	gdata->type = T_DEC;
	gdata->modifier = M_LL;
}

t_gdata	*signed_decimal_modifiers(char *str, va_list ap)
{
	t_gdata *gdata;

	gdata = (t_gdata *)ft_memalloc(sizeof(t_gdata));
	if (str[0] == 'l' && str[1] == 'l')
		load_lld(gdata, ap);
	else if (str[0] == 'l' || str[0] == T_LDEC)
		load_ld(gdata, ap);
	else if (str[0] == 'h' && str[1] == 'h')
		load_hhd(gdata, ap);
	else if (str[0] == 'h')
		load_hd(gdata, ap);
	else if (str[0] == 'j')
		load_jd(gdata, ap);
	else if (str[0] == 'z')
		load_zd(gdata, ap);
	else
		load_d(gdata, ap);
	return (gdata);
}
