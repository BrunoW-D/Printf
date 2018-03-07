#include "ft.h"

char	*ft_print_x(va_list ap, t_flags *flags)
{
	unsigned int	x;
	char			*ret;

	x = va_arg(ap, unsigned int);
	ret = ft_base(x, 16);
	if (flags->options[0])
		if ((ret = ft_realloc_free("0x", ret)) == NULL)
			return (NULL);
	return (ret);
}
