#include "ft_printf_helpers.h"

void	init_loader(t_ftype *ftype)
{
	if (ftype->type == T_DEC || ftype->type == T_BINARY)
		ftype->ltype = LT_SIGNED_DECIMAL;
	else if (ftype->type == T_UNSIGNED || ftype->type == T_OCT ||
			ftype->type == T_HEX ||
			ftype->type == T_BHEX ||
			ftype->type == T_LOCT)
		ftype->ltype = LT_UNSIGNED_DECIMAL;
	else if (ftype->type == T_STR)
		ftype->ltype = LT_STRING;
	else if (ftype->type == T_CHR || ftype->type == T_SPREAD)
		ftype->ltype = LT_CHAR;
	else if (ftype->type == T_PTR)
		ftype->ltype = LT_VOID_PTR;
}
