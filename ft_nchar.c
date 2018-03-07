#include "ft.h"

char	*ft_nchar (char c, size_t n)
{
	char	*str;
	size_t	i;

	str = ft_strnew(n);
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[n] = 0;
	return (str);
}
