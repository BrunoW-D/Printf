/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:35:45 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/29 17:22:02 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int        	init_flags(t_flags flags)
{
    int    i;

    i = 0;
    while (i < 5)
    {
        flags->options[i] = 0;
    }
    flags->modifier[0] = 0;
    flags->modifier[1] = 0;
    return (flags);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	char	*str;
	t_flags		flags;
	
	flags = init_flags(flags);
	if (format == NULL)
		return (0);
	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			str = ft_realloc(str, ft_get_flags(format, va_arg(ap, char *), flags));
		else
			str = ft_realloc(str, *format);
		format++;
	}
	va_end(ap);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int		main(void)
{
	wchar_t	*s1 = "Ceci";
	char	*s2 = "un";
	char	*s3 = "test";

	printf("%S est %s %s.\n", s1, s2, s3);
	return (0);
}
