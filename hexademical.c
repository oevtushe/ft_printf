char	*hex_manager(va_list ap, t_format *sfmt)
{
	char	*res;

	res = NULL;
	if (sfmt->MODIFIER_l)
		res = form_value(va_arg(ap, unsigned long int), sfmt, 16);
	else if (sfmt->MODIFIER_ll)
		res = form_value(va_arg(ap, unsigned long long int), sfmt, 16);
	else if (sfmt->MODIFIER_j)
		res = form_value(va_arg(ap, uintmax_t), sfmt, 16);
	else if (sfmt->MODIFIER_z)
		res = form_value(va_arg(ap, size_t), sfmt, 16);
	else
		res = form_value(va_arg(ap, unsigned int), sfmt, 16);
	return (res);
}
