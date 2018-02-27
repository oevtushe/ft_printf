#include "ft_printf_helpers.h"

static t_option	*new_option(char *abbr, char *value)
{
	t_option *opt;

	opt = (t_option *)ft_memalloc(sizeof(t_option));
	if (opt)
	{
		opt->abbr = abbr;
		opt->value = value;
	}
	return (opt);
}

static t_option	**get_spec_options(void)
{
    t_option **spec_options;

    spec_options = (t_option **)ft_memalloc(sizeof(t_option *) * (8 + 1));
    spec_options[0] = new_option("BOLD", BOLD);
    spec_options[1] = new_option("DBOLD", DBOLD);
    spec_options[2] = new_option("NBOLD", NBOLD);
    spec_options[3] = new_option("UNDERLINE", UNDERLINE);
    spec_options[4] = new_option("NUNDERLINE", NUNDERLINE);
    spec_options[5] = new_option("INVERSE", INVERSE);
    spec_options[6] = new_option("NINVERSE", NINVERSE);
    spec_options[7] = new_option("RESET", RESET);
    spec_options[8] = NULL;
    return (spec_options);
}

static t_option	**get_text_colors(void)
{
    t_option **text_colors;

	text_colors = (t_option **)ft_memalloc(sizeof(t_option *) * (8 + 1));
	text_colors[0] = new_option("BLACK", BLACK);
	text_colors[1] = new_option("RED", RED);
	text_colors[2] = new_option("GREEN", GREEN);
	text_colors[3] = new_option("YELLOW", YELLOW);
	text_colors[4] = new_option("BLUE", BLUE);
	text_colors[5] = new_option("MAGENTA", MAGENTA);
	text_colors[6] = new_option("CYAN", CYAN);
	text_colors[7] = new_option("GRAY", GRAY);
	text_colors[8] = NULL;
	return (text_colors);
}

static t_option	**get_background_colors(void)
{
	t_option **background_colors;

	background_colors = (t_option **)ft_memalloc(sizeof(t_option *) * (9 + 1));
	background_colors[0] = new_option("BGBLACK", BGBLACK);
	background_colors[1] = new_option("BGRED", BGRED);
	background_colors[2] = new_option("BGGREEN", BGGREEN);
	background_colors[3] = new_option("BGBROWN", BGBROWN);
	background_colors[4] = new_option("BGBLUE", BGBLUE);
	background_colors[5] = new_option("BGMAGENTA", BGMAGENTA);
	background_colors[6] = new_option("BGCYAN", BGCYAN);
	background_colors[7] = new_option("BGGRAY", BGGRAY);
	background_colors[8] = new_option("BGDEF", BGDEF);
	background_colors[9] = NULL;
	return (background_colors);
}

t_pretty	*get_pretty_st(void)
{
    t_pretty *pretty;

    pretty = (t_pretty *)ft_memalloc(sizeof(t_pretty));
	if (pretty)
	{
		pretty->spec_options = get_spec_options();
		pretty->text_colors = get_text_colors();
		pretty->background_colors = get_background_colors();
	}
	return (pretty);
}
