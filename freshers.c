#include "ft_printf.h"

void	free_defs(t_defaults **defs)
{
	int	i;
	char	**mds;

	i = -1;
	mds = (*defs)->all_modifiers;
	while (mds[++i])
		free(mds[i]);
	free(mds);
	free((*defs)->all_flags);
	free((*defs)->all_types);
	free(*defs);
}

void	del_sfmt(void *data, size_t size)
{
	t_format *sfmt;

	++size;
	sfmt = (t_format*)data;
	free(sfmt->flags);
	free(sfmt->modifier);
	free(sfmt);
}

void	del_simple(void *data, size_t size)
{
	++size;
	free(data);
}
