#ifndef _FT_PRINTF_HELPERS_H
# define _FT_PRINTF_HELPERS_H

# include "ft_tools.h"
# include "ft_structures.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/*
** Main logic
*/

char							*ft_format(const char *format, va_list ap, size_t *len);
t_gdata							*new_gdata(void);
void							free_gdata(t_gdata **gdata);
void							normalize_full_type(t_ftype *full_type);
t_ftype							*new_full_type(t_type type, t_modifier modifier);
int								get_arr_size(t_list *extra, int lt);
t_gdata							**get_data_arr(t_list *extra, va_list ap, int lt);
t_format						*format_parser(const char *str, int *di, t_gdata **gdata, int lt);
void							split_string(const char *format, t_list **plain, t_list **extra);
void							spaces_handling(char **sv, t_format *sfmt);
void							digits_flag_except(t_format *sfmt, int negative);
char							*get_format_string(const char *str, size_t *idx);
char							*init_types(void);
t_mng_dpc						**get_manager_dispatcher(void);
void							normalize_width(t_format *sfmt);
int								logic_type(t_list *extra);
void							percent_handler(const char *str, t_format *sfmt);
t_gdata							*get_cur_data(const char *str, size_t *idx, int *di, t_gdata **gdata);
int								outside_param(const char *str, size_t *idx, t_gdata **gdata, int *di);
void							validate_lists(const char *format, t_list **plain, t_list **extra);

int								is_type(char c);
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
void							unsigned_decimal_modifiers(t_ftype *full_type, va_list ap, t_gdata *gdata);
void							signed_decimal_modifiers(t_ftype *full_type, va_list ap, t_gdata *gdata);
void							zeroes_handling(char **val, int pref, t_format *sfmt);
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
void							str_modifiers(t_ftype *full_type, va_list ap, t_gdata *gdata);
void							chr_modifiers(t_ftype *full_type, va_list ap, t_gdata *gdata);
wint_t							ft_utu8(wint_t wcr);
char							*ft_witomb(wint_t wi);
int								read_data_index(const char *str, size_t *idx);

/*
** Other managers
*/

void							pos_modifiers(va_list ap, t_gdata *gdata);
char							*ptr_manager(t_format *sfmt, size_t *len);
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
