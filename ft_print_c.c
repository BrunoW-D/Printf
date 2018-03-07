#include "ft.h"

char	*ft_print_c(va_list ap, t_flags *flags)
{
	char	*ret;

	ret = ft_strnew(1);
	ret[0] = va_arg(ap, char);
	return (ret);
}
