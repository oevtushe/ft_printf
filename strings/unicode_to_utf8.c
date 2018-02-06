#include <wchar.h>

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

static unsigned int	get_tail(wchar_t val, unsigned int bp)
{
	int				bi;
	unsigned int	tmp;
	unsigned int	res;

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

int					unicode_to_utf8(wchar_t val)
{
	unsigned int	b1;
	unsigned int	b2;
	int				bc;
	size_t			bi;

	bi = sizeof(int) * 8;
	bc = bit_cnt(val);
	if (bc > 16 && bc <= 21)
	{
		b1 = get_tail(val, 3) | 0xF0808080;
		b2 = ((val >> 18) << (bi - 3)) >> (bi - 27);
	}
	else if (bc > 11 && bc <= 16)
	{
		b1 = get_tail(val, 2) | 0xE08080;
		b2 = ((val >> 12) << (bi - 4)) >> (bi - 20);
	}
	else if (bc > 7 && bc <= 11)
	{
		b1 = get_tail(val, 1) | 0xC080;
		b2 = ((val >> 6) << (bi - 5)) >> (bi - 13);
	}
	val = (b1 | b2);
	return (val);
}
