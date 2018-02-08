#include "ft_printf_helpers.h"

DATA_LOADER(uintmax_t, ju)
DATA_LOADER(unsigned long long int, llu)
DATA_LOADER(unsigned long int, lu)
DATA_LOADER(size_t, zu)
DATA_LOADER(unsigned int, u)

void	*unsigned_decimal_modifiers(char *str, va_list ap)
{
	int		*tmp;
	void	*data;

	data = NULL;
	if (str[0] == M_L && str[1] == M_L)
		data = load_llu(ap);
	else if (str[0] == M_L || str[0] == T_LUNSIGNED)
		data = load_lu(ap);
	else if (str[0] == M_H)
	{
		tmp = (int *)load_u(ap);
		if (str[1] == M_H)
			*tmp = (unsigned char)*tmp;
		else
			*tmp = (unsigned short)*tmp;
		data = tmp; 
	}
	else if (str[0] == M_J)
		data = load_ju(ap);
	else if (str[0] == M_Z)
		data = load_zu(ap);
	else
		data = load_u(ap);
	return (data);
}
