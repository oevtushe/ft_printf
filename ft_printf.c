#include "ft_printf.h"
#include "ft_printf_helpers.h"
#include <stdarg.h>
#include <stdio.h>//

char	*percent_manager(void)
{
	char *p;

	p = ft_strnew(1);
	p[0] = '%';
	return (p);
}

char	*undef_manager(t_format *sfmt)
{
	char *p;

	p = ft_strdup((char *)sfmt->data);
	return (p);
}

char	*mngr_usr(t_format *sfmt, int len)
{
	char	*res;

	res = NULL;
	if (sfmt->type == T_D)
		res = signed_decimal_manager(sfmt);
	else if (sfmt->type == T_U)
		res = unsigned_decimal_manager(sfmt);
	else if (sfmt->type == T_PT)
		res = percent_manager();
	else if (sfmt->type == T_PS)
		res = pos_manager(sfmt, len);
	else if (sfmt->type == T_S)
		res = str_manager(sfmt);
	else if (sfmt->type == T_C)
		res = chr_manager(sfmt);
	else
		res = undef_manager(sfmt);
	return (res);
}

char	*maker(t_list *plain, t_list *extra)
{
	char	*fmt;
	char	*str;
	char	*tmp;

	str = ft_strnew(0);
	while (extra)
	{
		fmt = mngr_usr((t_format*)extra->content, 
				ft_strlen(str) + ft_strlen(plain->content));
		tmp = str;
		str = easy_joiner(str, (char*)plain->content, fmt);
		free(tmp);
		free(fmt);
		plain = plain->next;
		extra = extra->next;
	}
	if (plain)
	{
		tmp = str;
		str = ft_strjoin(str, (char*)plain->content);
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

void	reformat_extra(t_list *extra, va_list ap)
{
	void		**data;
	int			di;
	t_format	*sfmt;
	int			is_dlr;

	di = 0;
	is_dlr = 0;
	data = get_data_arr(extra, ap);
	if (extra && ft_strchr(ALL_TYPES, 
				((char*)extra->content)[ft_strlen(extra->content) - 1]))
		is_dlr = logic_type((char *)extra->content);
	while (extra)
	{
		sfmt = format_parser((char *)extra->content, &di, data, is_dlr);
		free(extra->content);
		extra->content = sfmt;
		extra->content_size = sizeof(t_format);
		extra = extra->next;
	}
	free(data);
}

char	*ft_format(const char *format, va_list ap)
{
	char	*str;
	t_list	*plain;
	t_list	*extra;

	plain = NULL;
	extra = NULL;
	split_str(format, &plain, &extra);
	reformat_extra(extra, ap);
	str = maker(plain, extra);
	ft_lstdel(&plain, del_simple);
	ft_lstdel(&extra, del_extra);
	return (str);
}

int		ft_printf(const char *format, ...)
{
	int		len;
	va_list ap;
	char	*str;

	va_start(ap, format);
	str = ft_format(format, ap);
	ft_putstr(str);
	va_end(ap);
	len = ft_strlen(str);
	free(str);
	return (len);
}
