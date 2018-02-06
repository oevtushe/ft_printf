#include "ft_printf_helpers.h"

void	del_simple(void *data, size_t size)
{
	++size;
	if (data)
		free(data);
}

void	del_extra(void *data, size_t size)
{
	++size;
	if (data)
	{
		free(((t_format *)data)->data);
		free(data);
	}
}

void	void_ptr_arr_del(void ***dta)
{
	int		i;
	void	*tmp;

	i = 0;
	tmp = (*dta)[i];
	while (tmp)
	{
		free(tmp);
		tmp = (*dta)[++i];
	}
	free(*dta);
}
