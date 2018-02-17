#include "ft_printf_helpers.h"

t_gdata *new_gdata(void)
{
	t_gdata *gdata;

	gdata = (t_gdata *)ft_memalloc(sizeof(t_gdata));
	if (gdata)
	{
		gdata->full_type = (t_full_type *)ft_memalloc(sizeof(t_full_type));
		if (!gdata->full_type)
			ft_memdel((void **)&gdata);
	}
	return (gdata);
}
