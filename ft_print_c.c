#include "ft.h"

int		ft_print_c(va_list ap, t_flags *flags)
{
	char	c;
	char	*ret;

	(char)c = va_arg(ap, int);
	ret = ft_strnew(flags->options[3] + 2);
	ret = ft_strcpy(ft_nchar(' ', flags->options[3]));
	ret = ft_strcat(ret, &c);
	return (ret);
}
