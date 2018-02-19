#include "ft_printf_helpers.h"

void	free_gdata(t_gdata **gdata)
{
	ft_memdel((void **)&((*gdata)->full_type));
	ft_memdel((void **)gdata);
}