#include <unistd.h>

static void	ft_putstr(const char *str)
{
	char c;

	while ((c = *str++))
		write(1, &c, 1);
}

static void	print_hex(unsigned char c)
{
	unsigned char	tmp;
	char			byte[3];

	byte[0] = '0';
	byte[1] = '0';
	byte[2] = '\0';
	if (c < 16)
		byte[1] = (c < 10) ? (c + '0') : c - 10 + 'a';
	else
	{
		tmp = c % 16;
		byte[1] = (tmp < 10) ? (tmp + '0') : tmp - 10 + 'a';
		tmp = c / 16;
		byte[0] = (tmp < 10) ? (tmp + '0') : tmp - 10 + 'a';
	}
	ft_putstr(byte);
}

static void	print_chars(const unsigned char *data, size_t len)
{
	size_t	i;
	char	cd;

	i = 0;
	cd = '.';
	while (i < len)
	{
		if (data[i] >= ' ' && data[i] <= '~')
			write(1, &data[i], 1);
		else
			write(1, &cd, 1);
		++i;
	}
	ft_putstr("\n");
}

static void	fill_empty(const unsigned char *arr, size_t cnt, size_t pref, size_t size)
{
	int adx;

	adx = 40 - (size % 16) * 2;
	while (adx--)
		ft_putstr(" ");
	print_chars(arr + pref, cnt - pref);
}

void			print_memory(const void *addr, size_t size)
{
	size_t				cnt;
	const unsigned char *arr;
	size_t				pref;

	cnt = 0;
	arr = addr;
	pref = 0;
	while (cnt < size)
	{
		print_hex(arr[cnt]);
		++cnt;
		if (cnt && cnt % 2 == 0)
			ft_putstr(" ");
		if (cnt && cnt % 16 == 0)
		{
			print_chars(arr + pref, cnt - pref);
			pref = cnt;
		}
	}
	if (cnt % 16 != 0)
		fill_empty(arr, cnt, pref, size);
}
