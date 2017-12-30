#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

typedef	struct	s_assoc
{
	char	type;
	char	*(*manager)(t_format*, void*);
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

char			*string_manager(t_format *format, void *str)
{
	int		len;
	char	*res;
	char	*tmp;

	len  = (int)ft_strlen(str);
	res = (char*)str;
	if (format->precision < len)
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

int		ft_printf(const char *format, ...)
{
	va_list ap;
	char	*str;
	t_list	*plain;
	t_list	*extra;
	//t_list	*assocs;
	t_format *sfmt;

	plain = NULL;
	extra = NULL;
	//assocs = init_assocs();
	split_str(format, &plain, &extra);
	va_start(ap, format);
	while (extra)
	{
		sfmt = (t_format*)extra->content;
		if (sfmt->type == 's')
			str = string_manager(sfmt, va_arg(ap, const char *));
		else if (sfmt->type == 'd')
			str = decimal_manager(sfmt, va_arg(ap, int));
		ft_putstr(str);
	}
	va_end(ap);
	return (0);
}

/* str */
int		main(void)
{
	char format[] = "%-8.6s\n";
	char str[] = "lolchez";

	ft_printf(format, str);
	return (0);
}
