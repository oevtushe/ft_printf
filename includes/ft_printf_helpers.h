#ifndef _FT_PRINTF_HELPERS_H
# define _FT_PRINTF_HELPERS_H

#include "ft_tools.h"
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <wchar.h>
#include <unistd.h>

#define ALL_TYPES "sSpdDioOuUxXcCn"

typedef struct					s_full_type
{
	enum
	{
		T_UNDEF,
		T_DEC = 'd',
		T_DEC2 = 'i',
		T_LDEC = 'D',
		T_STR = 's',
		T_CHR = 'c',
		T_WCHR = 'C',
		T_UNSIGNED = 'u',
		T_LUNSIGNED = 'U',
		T_PT = '%',
		T_PS = 'n',
		T_WSTR = 'S',
		T_PTR = 'p',
		T_OCT = 'o',
		T_HEX = 'x',
		T_BHEX = 'X'
	}							type;
	enum
	{
		M_DEFAULT,
		M_L,
		M_LL,
		M_H,
		M_HH,
		M_J,
		M_Z
	}							modifier;
}								t_full_type;

typedef struct					s_gdata
{
	union
	{
		short int				si;
		unsigned short int		usi;

		int						i;
		long int				li;
		long long int			lli;
		ssize_t					sszi;
		size_t					szi;
		intmax_t				im;

		unsigned int			ui;
		unsigned long int		uli;
		unsigned long long int	ulli;
		uintmax_t				uim;

		char					c;
		unsigned char			uc;
		wchar_t					wc;
		wint_t					wi;
		char					*pc;
		wchar_t					*pwc;

		void					*pv;

	} 							data;
	t_full_type					*full_type;
}								t_gdata;

typedef struct					s_format
{
	int							width;
	int							precision;

	int							FLAG_PLUS;
	int							FLAG_MINUS;
	int							FLAG_SPACE;
	int							FLAG_ZERO;
	int							FLAG_SHARP;
	int							FLAG_SQUOTE;

	t_gdata						*gdata;
}								t_format;

/*
** Main logic
*/

t_gdata							*new_gdata(void);
int								get_arr_size(t_list *extra);
t_gdata							**get_data_arr(t_list *extra, va_list ap);
t_format						*format_parser(const char *str, int *di, t_gdata **gdata);
void							split_string(const char *format, t_list **plain, t_list **extra);
void							align(char **sv, t_format *sfmt);
void							decimal_flag_except(t_format *sfmt, int negative);
char							*get_format_string(const char *str, size_t *idx);
char							*init_types(void);

void							read_data_index(const char *str, size_t *idx);
void							read_width(const char *str, size_t *idx);
void							read_flags(const char *str, size_t *idx);
void							read_precision(const char *str, size_t *idx);
void							read_modifiers(const char *str, size_t *idx);
void							read_type(const char *str, size_t *idx);

/*
** Decimals
*/

char							*octal_manager(t_format *sfmt, size_t *len);
char							*hex_manager(t_format *sfmt, size_t *len);
char							*unsigned_decimal_manager(t_format *sfmt, size_t *len);
char							*signed_decimal_manager(t_format *sfmt, size_t *len);
void							unsigned_decimal_modifiers(char *str, va_list ap, t_gdata *gdata);
void							signed_decimal_modifiers(char *str, va_list ap, t_gdata *gdata);
void							width_and_prec(char **val, int pref, t_format *sfmt);
void							group_by_thousands(char **val);

void							load_hhd(t_gdata *gdata, va_list ap);
void							load_hd(t_gdata *gdata, va_list ap);
void							load_d(t_gdata *gdata, va_list ap);
void							load_zd(t_gdata *gdata, va_list ap);
void							load_jd(t_gdata *gdata, va_list ap);
void							load_ld(t_gdata *gdata, va_list ap);
void							load_lld(t_gdata *gdata, va_list ap);
void							load_hu(t_gdata *gdata, va_list ap);
void							load_hhu(t_gdata *gdata, va_list ap);
void							load_llu(t_gdata *gdata, va_list ap);
void							load_lu(t_gdata *gdata, va_list ap);
void							load_u(t_gdata *gdata, va_list ap);
void							load_ju(t_gdata *gdata, va_list ap);
void							load_zu(t_gdata *gdata, va_list ap);

/*
** Strings
*/

char							*str_manager(t_format *sfmt, size_t *ln);
char							*chr_manager(t_format *sfmt, size_t *len);
void							str_modifiers(char *type, va_list ap, t_gdata *gdata);
void							chr_modifiers(char *type, va_list ap, t_gdata *gdata);
unsigned int					unicode_to_utf8(wchar_t wcr);
char							*wcs_to_utf8(wchar_t *wcs, int len);
char							*ft_witomb(wint_t wi);

/*
** Other managers
*/

void							pos_modifiers(va_list ap, t_gdata *gdata);
char							*pos_manager(t_format *sfmt, int len, size_t *ln);
char							*ptr_manager(t_format *sfmt, size_t *len);
void							ptr_modifiers(va_list ap, t_gdata *gdata);
char							*percent_manager(t_format *sfmt, size_t *len);
char							*undef_manager(t_format *sfmt, size_t *fmt_len);


/*
** Freshers
*/

void							del_simple(void *data, size_t size);
void							del_extra(void *data, size_t size);
void							del_void_ptr_arr(void ***dta);
void							del_gdata_arr(t_gdata ***arr);

#endif
