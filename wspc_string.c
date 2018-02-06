char		*wspc_string(char **str, size_t new_len, char filler, char side)
{
	size_t	tjlen;
	char	*res;
	char	*to_join;

	tjlen = new_len - ft_wstrlen(*str);
	to_join = ft_strnew(tjlen * sizeof(wchar_t));
	ft_memset(to_join, filler, tjlen);
	if (side == '-')
		res = ft_wstrjoin(*str, to_join);
	else
		res = ft_wstrjoin(to_join, *str);
	free(str);
	free(to_join);
	return (res);
}
