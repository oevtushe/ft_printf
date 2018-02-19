/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:08:03 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 17:08:05 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

static char	*mngr_usr(t_format *sfmt, t_mng_dpc **dispatcher, int len, size_t *fmt_len)
{
	int			i;
	char		*res;

	i = -1;
	res = NULL;
	if (sfmt->gdata->full_type->type == T_PS)
		res = pos_manager(sfmt, len, fmt_len);
	else
	{
		while (++i < DISPATCHER_SIZE)
		{
			if (dispatcher[i]->type == sfmt->gdata->full_type->type)
			{
				res = dispatcher[i]->manager(sfmt, fmt_len);
				break;
			}
		}
	}
	return (res);
}

static char	*maker(t_list *plain, t_list *extra, size_t *len)
{
	char	*str;
	char	*extra_str;
	size_t	extra_len;
	t_mng_dpc 	**dispatcher;

	str = ft_strnew(0);
	dispatcher = get_manager_dispatcher();
	while (extra)
	{
		extra_str = mngr_usr(extra->content, dispatcher, *len, &extra_len);
		ft_memconnect((void**)&str, *len, plain->content, ft_strlen(plain->content));
		*len += ft_strlen(plain->content);
		ft_memconnect((void**)&str, *len, extra_str, extra_len);
		*len += extra_len;
		plain = plain->next;
		extra = extra->next;
		ft_memdel((void **)&extra_str);
	}
	if (plain)
	{
		ft_memconnect((void**)&str, *len, plain->content, ft_strlen(plain->content));
		*len += ft_strlen(plain->content);
	}
	del_void_ptr_arr((void***)&dispatcher);
	return (str);
}

static void	reformat_extra(t_list *extra, t_gdata **gdata)
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