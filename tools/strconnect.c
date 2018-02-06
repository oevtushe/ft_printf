#include "ft_printf_helpers.h"

/*
** If ft_strnew fails to allocate new string
** previous data in *s1 stay untouched.
*/

void		strconnect(char **s1, char *s2)
{
	char *tmp;

	if (s1 && s2)
	{
		if (!*s1)
			*s1 = ft_strnew(0);
		if (*s1)
		{
			tmp = *s1;
			*s1 = ft_strjoin(*s1, s2);
			if (*s1)
				ft_strdel(&tmp);
			else
				*s1 = tmp;
		}
	}
}
