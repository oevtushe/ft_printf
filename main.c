#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

typedef	struct	s_assoc
{
	char	type;
	char	*(*manager)(t_format*, const void*);
}				t_assoc;

char			*reformat_string(char *str, size_t new_len, char filler, char side)
{
	size_t	tjlen;
	char	*res;
	char	*to_join;

	tjlen = new_len - ft_strlen(str);
	to_join = ft_strnew(tjlen);
	ft_memset(to_join, filler, tjlen);
	if (side == '-')
		res = ft_strjoin(str, to_join);
	else
		res = ft_strjoin(to_join, str);
	return (res);
}

char			*string_manager(t_format *format, const void *str)
{
	int		len;
	char	*res;
	char	*tmp;

	len  = (int)ft_strlen(str);
	res = ft_strdup(str);
	if (format->precision >= 0 && format->precision < len)
	{
		res = ft_strsub(res, 0, format->precision);
	}
	if (format->width > len)
	{
		len = format->width;
		if (ft_strchr(format->flags, FLAG_MINUS))
		{
			tmp = res;
			res = reformat_string(res, len, ' ', FLAG_MINUS);
			ft_strdel(&tmp);
		}
		else
		{
			tmp = res;
			res = reformat_string(res, len, ' ', 0);
			ft_strdel(&tmp);
		}
	}
	/* modifiers */
	return (res);
}

t_list			*init_assocs(void)
{
	t_list	*lst;
	t_list	*new_elem;
	t_assoc *assoc;

	lst = NULL;
	assoc = (t_assoc*)malloc(sizeof(t_assoc));
	assoc->type = 's';
	assoc->manager = string_manager;
	new_elem = ft_lstnew(assoc, sizeof(t_assoc));
	ft_lstappend(&lst, new_elem);
	return (lst);
}

/*
char
unsigned char
short
unsigned short
const char *
double
long double
void *
int
long
long long
unsigned int
unsigned long
unsigned long long
*/

t_assoc	*get_mngr(t_list *lst, char type)
{
	t_assoc	*cur;

	cur = NULL;
	while (lst)
	{
		cur = (t_assoc*)lst->content;
		if (cur->type == type)
			break ;
		lst = lst->next;
	}
	return (cur);
}

char	*mngr_usr(va_list ap, t_format *sfmt, t_list *assocs)
{
	char	*res;
	t_assoc	*cur;

	res = NULL;
	cur = get_mngr(assocs, sfmt->type);
	if (sfmt->type == 's')
		res = cur->manager(sfmt, va_arg(ap, const char *));
	return (res);
}

char	*easy_joiner(char *str, char *fst, char *scd)
{
	char *tmp;
	char *res;

	res = ft_strjoin(str, fst);
	tmp = res;
	res = ft_strjoin(str, scd);
	free(tmp);
	return (res);
}

void	del_sfmt(void *data, size_t size)
{
	t_format *sfmt;

	++size;
	sfmt = (t_format*)data;
	free(sfmt->flags);
	free(sfmt->modifier);
	free(sfmt);
}

void	del_str(void *data, size_t size)
{
	++size;
	free(data);
}

char	*maker(t_list *plain, t_list *extra, va_list ap)
{
	char	*fmt;
	char	*str;
	char	*tmp;
	t_list	*assocs;

	assocs = init_assocs();
	str = ft_strnew(0);
	while (extra)
	{
		fmt = mngr_usr(ap, (t_format*)extra->content, assocs);
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

int		ft_printf(const char *format, ...)
{
	va_list ap;
	va_list	cap;
	char	*str;
	t_list	*plain;
	t_list	*extra;

	plain = NULL;
	extra = NULL;
	split_str(format, &plain, &extra);
	va_start(ap, format);
	va_copy(cap, ap);
	str = maker(plain, extra, cap);
	ft_putstr(str);
	va_end(ap);
	ft_lstdel(&plain, del_str);
	ft_lstdel(&extra, del_sfmt);
	return (ft_strlen(str));
}

/* str */
int		main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	ft_printf(argv[1], argv[2]);
	return (0);
}
