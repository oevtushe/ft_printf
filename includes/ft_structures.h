/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:49:19 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:58:37 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_STRUCTURES_H
# define _FT_STRUCTURES_H
# include <string.h>
# include <inttypes.h>
# include <wchar.h>

# define DISPATCHER_SIZE 10

/*
** Special options for pretty.
*/

# define BOLD "\033[1m"
# define DBOLD "\033[2m"
# define NBOLD "\033[22m"
# define UNDERLINE "\033[4m"
# define NUNDERLINE "\033[4m"
# define INVERSE "\033[7m"
# define NINVERSE "\033[7m"
# define RESET "\033[m"

/*
** Text colors.
*/

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GRAY "\033[37m"

/*
** Background colors.
*/

# define BGBLACK "\033[40m"
# define BGRED "\033[41m"
# define BGGREEN "\033[42m"
# define BGBROWN "\033[43m"
# define BGBLUE "\033[44m"
# define BGMAGENTA "\033[45m"
# define BGCYAN "\033[46m"
# define BGGRAY "\033[47m"
# define BGDEF "\033[49m"

typedef enum					e_type
{
	T_DEC = 'd',
	T_DEC2 = 'i',
	T_LDEC = 'D',
	T_STR = 's',
	T_CHR = 'c',
	T_WCHR = 'C',
	T_UNSIGNED = 'u',
	T_LUNSIGNED = 'U',
	T_PT = '%',
	T_WSTR = 'S',
	T_PTR = 'p',
	T_OCT = 'o',
	T_LOCT = 'O',
	T_HEX = 'x',
	T_BINARY = 'b',
	T_BHEX = 'X'
}								t_type;

typedef enum					e_modifier
{
	M_DEFAULT,
	M_L,
	M_LL,
	M_H,
	M_HH,
	M_J,
	M_Z
}								t_modifier;

typedef union					u_data
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

}								t_data;

typedef struct					s_full_type
{
	t_type		type;
	t_modifier	modifier;
}								t_ftype;

typedef struct					s_gdata
{
	t_data					data;
	t_ftype					*full_type;
}								t_gdata;

typedef struct					s_format
{
	int						width;
	int						precision;

	int						flag_plus;
	int						flag_minus;
	int						flag_space;
	int						flag_zero;
	int						flag_sharp;
	int						flag_squote;

	t_gdata					*gdata;
}								t_format;
typedef struct					s_mng_dpc
{
	t_type	type;
	char	*(*manager)(t_format *sfmt, size_t *len);
}								t_mng_dpc;

typedef struct					s_option
{
	char	*abbr;
	char	*value;
}								t_option;

typedef	struct					s_pretty
{
	t_option	**text_colors;
	t_option	**background_colors;
	t_option	**spec_options;
}								t_pretty;

#endif
