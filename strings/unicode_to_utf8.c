/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_to_utf8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:40:50 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:40:52 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf_helpers.h"
#include <stdio.h>

static int			bit_cnt(wchar_t val)
{
	int		cnt;

	cnt = 0;
	while (val)
	{
		++cnt;
		val >>= 1;
	}
	return (cnt);
}

static unsigned int get_tail(wint_t val, unsigned int bp)
{
	int				bi;
	unsigned int			tmp;
	unsigned int			res;

	bi = sizeof(int) * 8;
	res = 0;
	tmp = val;
	if (bp > 0)
	{
		while (bp--)
		{
			tmp >>= 6 * bp;
			tmp = (tmp << (bi - 6)) >> (bi - 6);
			tmp <<= 8 * bp;
			res |= tmp;
			tmp = val;
		}
	}
	return (res);
}

/*
** 0xC080 	  -> 110xxxxx 10xxxxxx
** 0xE08080   -> 1110xxxx 10xxxxxx 10xxxxxx
** 0xF0808080 -> 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/
void			print_memory(void *data, size_t size);
wint_t	unicode_to_utf8(wint_t val)
{
	wint_t		b1;
	wint_t		b2;
	int			bc;
	size_t		bi;

	bi = sizeof(wint_t) * 8;
	bc = bit_cnt(val);
	b1 = 0;
	b2 = 0;
	if (bc <= 7)
		return (val);
	if (bc > 16 && bc <= 21)
	{
		b1 = get_tail(val, 3) | 0xF0808080;
		b2 = (unsigned int)((val >> 18) << (bi - 3)) >> (bi - 27);
	}
	else if (bc > 11 && bc <= 16)
	{
		b1 = get_tail(val, 2) | 0xE08080;
		b2 = (unsigned int)((val >> 12) << (bi - 4)) >> (bi - 20);
	}
	else if (bc > 7 && bc <= 11)
	{
		b1 = get_tail(val, 1) | 0xC080;
		b2 = (unsigned int)((val >> 6) << (bi - 5)) >> (bi - 13);
	}
	return (b1 | b2);
}
