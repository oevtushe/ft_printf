#include "ft_printf_helpers.h"

char	*undef_manager(t_format *sfmt, size_t *fmt_len)
{
	char *rs;

	rs = sfmt->gdata->data.pc;
	*fmt_len = ft_strlen(rs);
	ft_memdel((void **)&(sfmt->gdata));
	return (rs);
}
