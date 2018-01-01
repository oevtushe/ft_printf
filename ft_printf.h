#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

#include "libft.h"
#include <stdlib.h>

# define FLAG_PLUS '+'
# define FLAG_MINUS '-'
# define FLAG_ZERO '0'
# define FLAG_SPACE ' '

# define TYPE_STRING 's'
# define TYPE_DECIMAL 'd'
# define TYPE_FLOAT 'f'

# define MODIFIER_h "h"
# define MODIFIER_hh "hh"
# define MODIFIER_l "l"
# define MODIFIER_ll "ll"
# define MODIFIER_L "L"

typedef	struct	s_format
{
	char	*flags;
	int		width;
	int		precision;
	char	*modifier;
	char	type;
}				t_format;

typedef	struct	s_defaults
{
	char	*all_flags;
	char	*all_types;
	char	**all_modifiers;
}				t_defaults;

typedef	struct	s_assoc
{
	char	type;
	char	*(*manager)(t_format*, const void*);
}				t_assoc;

t_format		*format_parser(const char *str, t_defaults *defaults, size_t *idx);
void			ft_strappend(char **str, char c);
void			split_str(const char *format, t_list **plain, t_list **extra);
char			*spc_string(char **str, size_t new_len, char filler, char side);

/* initializers */
t_defaults		*init_defaults(void);
t_list			*init_assocs(void);

/* managers */
char			*string_manager(t_format *format, const void *data);
char			*decimal_manager(t_format *format, const void *data);

/* freshers */
void			del_simple(void *data, size_t size);
void			del_sfmt(void *data, size_t size);
void			free_defs(t_defaults **defs);
#endif
