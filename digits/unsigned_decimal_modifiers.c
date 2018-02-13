#include "ft_printf_helpers.h"

void	load_llu(t_gdata *gdata, va_list ap)
{
	gdata->data.ulli = va_arg(ap, long long int);
	gdata->type = T_UNSIGNED;
	gdata->modifier = M_LL;
}

void	load_lu(t_gdata *gdata, va_list ap)
{
	gdata->data.uli = va_arg(ap, long int);
	gdata->type = T_UNSIGNED;
	gdata->modifier = M_L;
}

void	load_u(t_gdata *gdata, va_list ap)
{
	gdata->data.ui = va_arg(ap, unsigned int);
	gdata->type = T_UNSIGNED;
	gdata->modifier = M_DEFAULT;
}

void	load_ju(t_gdata *gdata, va_list ap)
{
	gdata->data.uim = va_arg(ap, uintmax_t);
	gdata->type = T_UNSIGNED;
	gdata->modifier = M_J;
}

void	load_zu(t_gdata *gdata, va_list ap)
{
	gdata->data.szi = va_arg(ap, size_t);
	gdata->type = T_UNSIGNED;
	gdata->modifier = M_Z;
}

void	load_hu(t_gdata *gdata, va_list ap)
{
	gdata->data.usi = va_arg(ap, unsigned int);
	gdata->type = T_UNSIGNED;
	gdata->modifier = M_H;
}

void	load_hhu(t_gdata *gdata, va_list ap)
{
	gdata->data.uc = va_arg(ap, unsigned int);
	gdata->type = T_UNSIGNED;
	gdata->modifier = M_HH;
}

t_gdata	*unsigned_decimal_modifiers(char *str, va_list ap)
{
	t_gdata *gdata;

	gdata = (t_gdata *)ft_memalloc(sizeof(t_gdata));
	if (str[0] == 'l' && str[1] == 'l')
		load_llu(gdata, ap);
	else if (str[0] == 'l' || str[0] == T_LUNSIGNED)
		load_lu(gdata, ap);
	else if (str[0] == 'h' && str[1] == 'h')
		load_hhu(gdata, ap);
	else if (str[0] == 'h')
		load_hu(gdata, ap);
	else if (str[0] == 'j')
		load_ju(gdata, ap);
	else if (str[0] == 'z')
		load_zu(gdata, ap);
	else
		load_u(gdata, ap);
	return (gdata);
}
