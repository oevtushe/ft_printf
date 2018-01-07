#include "ft_printf.h"
#include "ft_printf_helpers.h"
#include <stdarg.h>
#include <stdio.h>//

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

/* Default

   char
   int
   double

   const char *
   const void *

   unsigned
*/

/* Modifiers

   short
   long int
   long double
   long long int
   short

   unsigned long int
   unsigned long long int

   unsigned short
*/

char	*mngr_usr(va_list ap, t_format *sfmt)
{
	char	*res;

	res = NULL;
	/*
	if (sfmt->type == 's')
		res = string_manager(sfmt, va_arg(ap, const char *));
		*/
	if (sfmt->type == 'd')
		res = signed_decimal_manager(ap, sfmt);
	/*
	else if (sfmt->type == 'u')
		res = unsigned_decimal_manager(ap, sfmt);
		*/
	return (res);
}

char	*maker(t_list *plain, t_list *extra, va_list ap)
{
	char	*fmt;
	char	*str;
	char	*tmp;

	str = ft_strnew(0);
	while (extra)
	{
		fmt = mngr_usr(ap, (t_format*)extra->content);
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
	int		len;
	char	*str;
	t_list	*plain;
	t_list	*extra;

	plain = NULL;
	extra = NULL;
	va_start(ap, format);
	split_str(format, &plain, &extra, ap);
	str = maker(plain, extra, ap);
	ft_putstr(str);
	len = (int)ft_strlen(str);
	va_end(ap);
	free(str);
	ft_lstdel(&plain, del_simple);
	ft_lstdel(&extra, del_simple);
	return (len);
}
