#ifndef _FT_PRINTF_HELPERS_H
# define _FT_PRINTF_HELPERS_H

#include "ft_tools.h"
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

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
	int		MODIFIER_j;
	int		MODIFIER_z;
}				t_format;

t_format		*format_parser(const char *str, const char *all_types, size_t *idx, va_list ap);
void			split_str(const char *format, t_list **plain, t_list **extra);
char			*align(char **sv, t_format *sfmt);
void			decimal_flag_except(t_format *sfmt, int negative);
char			*form_value(uintmax_t val, int sign, t_format *sfmt);
char			*get_format_str(const char *str, size_t *idx, char *all_types);
char			*init_types(void);

/* managers */
char			*signed_decimal_manager(va_list ap, t_format *sfmt);

/* freshers */
void			del_simple(void *data, size_t size);
#endif
