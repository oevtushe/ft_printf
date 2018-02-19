#include "ft_printf_helpers.h"

t_full_type *new_full_type(t_type type, t_modifier modifier)
{
	t_full_type *full_type;

	full_type = (t_full_type *)ft_memalloc(sizeof(t_full_type));
	full_type->type = type;
	full_type->modifier = modifier;
	return (full_type);
}