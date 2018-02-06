#include "ft_printf_helpers.h"

static int	get_idx(const char *str, int *i)
{
	int j;
	int	val;

	j = *i;
	val = 0;
	if (ft_isdigit(str[*i]))
	{
		val = ft_atoi(&str[*i]);
		while (ft_isdigit(str[j]))
			++j;
		if (str[j] == '$')
			*i = j;
		else
			val = 0;
	}
	return (val);
}

static int	get_max_idx_dl(const char *str)
{
	int		i;
	int		cur_max;
	int		tmp;
	char	*pos;

	i = 1;
	cur_max = get_idx(str, &i);
	while ((pos = ft_strchr(&str[i], '*')))
	{
		i = pos - str;
		++i;
		tmp = get_idx(str, &i);
		cur_max = (tmp > cur_max) ? tmp : cur_max;
	}
	return (cur_max);
}

static int	get_max_idx_smp(const char *str)
{
	char	*pos;
	int		idx;
	int		prev;

	idx = 1;
	prev = 0;
	while ((pos = ft_strchr(&str[prev], '*')))
	{
		++idx;
		prev = pos - str + 1;
	}
	return (idx);
}

int			get_arr_size(t_list *extra)
{
	char	*cur;
	int		tmp;
	int		max;

	tmp = 0;
	max = 0;
	while (extra)
	{
		cur = (char*)extra->content;
		tmp = get_max_idx_dl(cur);
		if (!tmp)
		{
			tmp = get_max_idx_smp(cur);
			max += tmp;
		}
		else
			max = (tmp > max) ? tmp : max;
		extra = extra->next;
	}
	return (max);
}
