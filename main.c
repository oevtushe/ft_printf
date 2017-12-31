#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

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

/*
   char
   short
   int
   float

   const char *
   const void *

   unsigned
*/

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
	res = ft_strjoin(res, scd);
	free(tmp);
	return (res);
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
	ft_lstdel(&assocs, del_simple);
	return (str);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		len;
	char	*str;
	t_list	*plain;
	t_list	*extra;

	plain = NULL;
	extra = NULL;
	split_str(format, &plain, &extra);
	va_start(ap, format);
	str = maker(plain, extra, ap);
	ft_putstr(str);
	len = (int)ft_strlen(str);
	va_end(ap);
	free(str);
	ft_lstdel(&plain, del_simple);
	ft_lstdel(&extra, del_sfmt);
	return (len);
}

/* str */
int		main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	ft_printf(argv[1], argv[2]);
	return (0);
}
