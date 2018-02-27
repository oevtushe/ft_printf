#include "ft_printf_helpers.h"

static char	*check_opt_arr(t_option **arr, const char *abbr)
{
	int		i;
	char	*val;
	
	i = -1;
	val = NULL;
	while (arr[++i])
	{
		if (!ft_strcmp(arr[i]->abbr, abbr))
		{
			val = ft_strdup(arr[i]->value);
			break ;
		}
	}
	return (val);
}

char		*get_pretty_vl(t_pretty *pretty, char *abbr)
{
	char *clr;

	clr = NULL;
	if ((clr = check_opt_arr(pretty->spec_options, abbr)))
		return (clr);
	else if ((clr = check_opt_arr(pretty->text_colors, abbr)))
		return (clr);
	else if ((clr = check_opt_arr(pretty->background_colors, abbr)))
		return (clr);
	return (clr);
}
