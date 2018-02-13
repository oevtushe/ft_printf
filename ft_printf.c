#include "ft_printf.h"
#include "ft_printf_helpers.h"
#include <stdarg.h>
#include <stdio.h>//

char	*percent_manager(size_t *len)
{
	char *p;

	p = ft_strnew(1);
	p[0] = '%';
	*len = 1;
	return (p);
}

char	*undef_mngr(t_format *sfmt, size_t *fmt_len)
{
	char *rs;

	rs = sfmt->gdata->data.pc;
	*fmt_len = ft_strlen(rs);
	ft_memdel((void **)&(sfmt->gdata));
	return (rs);
}

char	*mngr_usr(t_format *sfmt, int len, size_t *fmt_len)
{
	char	*res;

	res = NULL;
	if (sfmt->gdata->type == T_DEC || sfmt->gdata->type == T_DEC2 || sfmt->gdata->type == T_LDEC)
		res = signed_decimal_manager(sfmt, fmt_len);
	else if (sfmt->gdata->type == T_UNSIGNED || sfmt->gdata->type == T_LUNSIGNED)
		res = unsigned_decimal_manager(sfmt, fmt_len);
	else if (sfmt->gdata->type == T_PS)
		res = pos_manager(sfmt, len, fmt_len);
	else if (sfmt->gdata->type == T_PT)
		res = percent_manager(fmt_len);
	else if (sfmt->gdata->type == T_STR || sfmt->gdata->type == T_WSTR)
		res = str_manager(sfmt, fmt_len);
	else if (sfmt->gdata->type == T_CHR || sfmt->gdata->type == T_WCHR)
		res = chr_manager(sfmt, fmt_len);
	else if (sfmt->gdata->type == T_PTR)
		res = ptr_manager(sfmt, fmt_len);
	else if (sfmt->gdata->type == T_OCT)
		res = octal_manager(sfmt, fmt_len);
	else if (sfmt->gdata->type == T_HEX || sfmt->gdata->type == T_BHEX)
		res = hex_manager(sfmt, fmt_len);
	else
		res = undef_mngr(sfmt, fmt_len);
	return (res);
}

void	*ft_memjoin(void *p1, size_t sp1, void *p2, size_t sp2)
{
	unsigned char *res;

	res = (unsigned char *)malloc(sizeof(unsigned char) * (sp1 + sp2));
	ft_memcpy(res, p1, sp1);
	ft_memcpy(res + sp1, p2, sp2);
	return (res);
}

void	tripple_connector(char **res, size_t *res_len, char *plain, t_format *sfmt)
{
	size_t	fmt_len;
	size_t	plc_len;
	char	*fmt;
	char	*tmp1;
	char	*tmp2;

	plc_len = ft_strlen(plain);
	fmt = mngr_usr(sfmt, *res_len + plc_len, &fmt_len);
	tmp1 = ft_memjoin(plain, plc_len, fmt, fmt_len);
	tmp2 = *res;
	*res = ft_memjoin(*res, *res_len, tmp1, plc_len + fmt_len);
	*res_len += plc_len + fmt_len;
	free(tmp1);
	free(tmp2);
	free(fmt);
}

char	*maker(t_list *plain, t_list *extra, size_t *len)
{
	char	*str;
	char	*tmp;

	str = ft_strnew(0);
	while (extra)
	{
		tripple_connector(&str, len, plain->content, extra->content);
		plain = plain->next;
		extra = extra->next;
	}
	if (plain)
	{
		tmp = str;
		str = ft_memjoin(str, *len, plain->content, ft_strlen(plain->content));
		*len += ft_strlen(plain->content);
		free(tmp);
	}
	return (str);
}

int		logic_type(const char *str)
{
	int i;
	int type;

	i = 1;
	type = 0;
	while (ft_isdigit(str[i]))
		++i;
	if (str[i] == '$')
		type = 1;
	return (type);
}

/*
** free(data) -> all arr content catched by struct
*/

void	reformat_extra(t_list *extra, t_gdata **gdata)
{
	int			di;
	t_format	*sfmt;
	int			is_dlr;

	di = 0;
	is_dlr = 0;
	if (extra && ft_strchr(ALL_TYPES, 
				((char*)extra->content)[ft_strlen(extra->content) - 1]))
		is_dlr = logic_type((char *)extra->content);
	while (extra)
	{
		sfmt = format_parser((char *)extra->content, &di, gdata, is_dlr);
		free(extra->content);
		extra->content = sfmt;
		extra->content_size = sizeof(t_format);
		extra = extra->next;
	}
}

char	*ft_format(const char *format, va_list ap, size_t *len)
{
	char	*str;
	t_list	*plain;
	t_list	*extra;
	t_gdata	**gdata;

	plain = NULL;
	extra = NULL;
	split_str(format, &plain, &extra);
	gdata = get_data_arr(extra, ap);
	reformat_extra(extra, gdata);
	str = maker(plain, extra, len);
	ft_lstdel(&plain, del_simple);
	ft_lstdel(&extra, del_extra);
	void_ptr_arr_del((void ***)&gdata);
	return (str);
}

void	ft_putstr_ln(const char *str, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
		write(1, &str[i++], 1);
}

int		ft_printf(const char *format, ...)
{
	size_t	len;
	va_list ap;
	char	*str;

	len = 0;
	va_start(ap, format);
	str = ft_format(format, ap, &len);
	ft_putstr_ln(str, len);
	va_end(ap);
	free(str);
	return (len);
}
