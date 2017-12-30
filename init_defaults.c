#include "ft_printf.h"

static char	*init_flags(void)
{
	char *res;

	res = ft_strnew(4);
	res[0] = FLAG_PLUS;
	res[1] = FLAG_MINUS;
	res[2] = FLAG_ZERO;
	res[3] = FLAG_SPACE;
	return (res);
}

static char	*init_types(void)
{
	char *res;

	res = ft_strnew(3);
	res[0] = TYPE_STRING;
	res[1] = TYPE_DECIMAL;
	res[2] = TYPE_FLOAT;
	return (res);
}

static char	**init_modifiers(void)
{
	char **res;

	res = (char**)malloc(sizeof(char*) * 6);
	res[0] = ft_strdup(MODIFIER_hh);
	res[1] = ft_strdup(MODIFIER_ll);
	res[2] = ft_strdup(MODIFIER_h);
	res[3] = ft_strdup(MODIFIER_l);
	res[4] = ft_strdup(MODIFIER_L);
	res[5] = NULL;
	return (res);
}

t_defaults	*init_defaults(void)
{
	t_defaults	*res;
	char		*all_flags;
	char		*all_types;
	char		**all_modifiers;

	all_flags = init_flags();
	all_types = init_types();
	all_modifiers = init_modifiers();
	res = (t_defaults*)malloc(sizeof(t_defaults));
	res->all_flags = all_flags;
	res->all_types = all_types;
	res->all_modifiers = all_modifiers;
	return (res);
}
