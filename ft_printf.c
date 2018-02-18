/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:00 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:48:01 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_helpers.h"
#include <stdarg.h>

char	*mngr_usr(t_format *sfmt, int len, size_t *fmt_len)
{
	char	*res;

	res = NULL;
	if (sfmt->gdata->full_type->type == T_DEC || sfmt->gdata->full_type->type == T_DEC2 || sfmt->gdata->full_type->type == T_LDEC)
		res = signed_decimal_manager(sfmt, fmt_len);
	else if (sfmt->gdata->full_type->type == T_UNSIGNED || sfmt->gdata->full_type->type == T_LUNSIGNED)
		res = unsigned_decimal_manager(sfmt, fmt_len);
	else if (sfmt->gdata->full_type->type == T_PS)
		res = pos_manager(sfmt, len, fmt_len);
	else if (sfmt->gdata->full_type->type == T_PT)
		res = percent_manager(sfmt, fmt_len);
	else if (sfmt->gdata->full_type->type == T_STR || sfmt->gdata->full_type->type == T_WSTR)
		res = str_manager(sfmt, fmt_len);
	else if (sfmt->gdata->full_type->type == T_CHR || sfmt->gdata->full_type->type == T_WCHR)
		res = chr_manager(sfmt, fmt_len);
	else if (sfmt->gdata->full_type->type == T_PTR)
		res = ptr_manager(sfmt, fmt_len);
	else if (sfmt->gdata->full_type->type == T_OCT)
		res = octal_manager(sfmt, fmt_len);
	else if (sfmt->gdata->full_type->type == T_HEX || sfmt->gdata->full_type->type == T_BHEX)
		res = hex_manager(sfmt, fmt_len);
	else
		res = undef_manager(sfmt, fmt_len);
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

void	reformat_extra(t_list *extra, t_gdata **gdata)
{
	int			di;
	t_format	*sfmt;

	di = 0;
	while (extra)
	{
		sfmt = format_parser((char *)extra->content, &di, gdata);
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
	split_string(format, &plain, &extra);
	gdata = get_data_arr(extra, ap);
	reformat_extra(extra, gdata);
	str = maker(plain, extra, len);
	ft_lstdel(&plain, del_simple);
	ft_lstdel(&extra, del_extra);
	del_gdata_arr(&gdata);
	return (str);
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
