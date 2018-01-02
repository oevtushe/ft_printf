#ifndef _FT_PRINTF_HELPERS_H
# define _FT_PRINTF_HELPERS_H

#include "ft_tools.h"
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_format
{
	char	type;
	int		width;
	int		precision;
	
	int		FLAG_PLUS;
	int		FLAG_MINUS;
	int		FLAG_SPACE;
	int		FLAG_ZERO;

	int		MODIFIER_l;
	int		MODIFIER_ll;
	int		MODIFIER_h;
	int		MODIFIER_hh;
	int		MODIFIER_L;
}				t_format;

t_format		*format_parser(const char *str, const char *all_types, size_t *idx);
void			split_str(const char *format, t_list **plain, t_list **extra);

/* managers */
char			*decimal_manager(va_list ap, t_format *sfmt);

/* freshers */
void			del_simple(void *data, size_t size);
#endif
