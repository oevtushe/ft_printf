#ifndef _FT_PRINTF_HELPERS_H
# define _FT_PRINTF_HELPERS_H

#include "ft_tools.h"
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <wchar.h>

#define ALL_TYPES "sSpdDioOuUxXcCeEfFgGaAn"

#define DATA_LOADER(type, tn)\
	static void	*load_##tn(va_list ap)\
	{\
		type val;\
		\
		val = va_arg(ap, type);\
		return (ft_memdup(((void*)&val), sizeof(val)));\
	}

typedef struct	s_format
{
	int		width;
	int		precision;
	void	*data;

	int		FLAG_PLUS;
	int		FLAG_MINUS;
	int		FLAG_SPACE;
	int		FLAG_ZERO;

	enum
	{
		T_UNDEF, T_DEC = 'd', T_DEC2 = 'i', T_STR = 's',
		T_CHR = 'c', T_WCHR = 'C', T_UNSIGNED = 'u',
		T_PT = '%', T_PS = 'n', T_WSTR = 'S',
		T_PTR = 'p', T_OCT = 'o'
	}		type;
	enum
	{
		M_DEFAULT, M_L, M_LL, M_H, M_HH,
		M_J, M_Z
	}		modifier;
}				t_format;

int				get_arr_size(t_list *extra);
void			**get_data_arr(t_list *extra, va_list ap);
t_format		*format_parser(const char *str, int *di, void **data, int is_dlr);
void			split_str(const char *format, t_list **plain, t_list **extra);
void			align(char **sv, t_format *sfmt);
void			decimal_flag_except(t_format *sfmt, int negative);
char			*get_format_str(const char *str, size_t *idx);
char			*init_types(void);
void			*dec_ptr_modifiers(va_list ap);
char			*pos_manager(t_format *sfmt, int len);
void			*str_modifiers(char *type, va_list ap);
char			*ptr_manager(t_format *sfmt);
void			*ptr_modifiers(va_list ap);

/*
** Decimals
*/

intmax_t		gen_load_unsd(t_format *sfmt);
char			*octal_manager(t_format *sfmt);
char			*unsigned_decimal_manager(t_format *sfmt);
char			*octal_manager(t_format *sfmt);
char			*signed_decimal_manager(t_format *sfmt);
void			*unsigned_decimal_modifiers(char *str, va_list ap);
void			*signed_decimal_modifiers(char *str, va_list ap);
void			form_value(char **val, int sign, t_format *sfmt);

/*
** Strings
*/

char			*str_manager(t_format *sfmt);
void			*chr_modifiers(char *type, va_list ap);
char			*chr_manager(t_format *sfmt);
unsigned int	unicode_to_utf8(wchar_t wcr);
char			*wcs_to_utf8(wchar_t *wcs);
char			*ft_witomb(wint_t wi);

/*
** Freshers
*/

void			del_simple(void *data, size_t size);
void			del_extra(void *data, size_t size);
void			void_ptr_arr_del(void ***dta);

#endif
