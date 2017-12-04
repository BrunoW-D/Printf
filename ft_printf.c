/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:35:45 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/04 15:11:02 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/*
int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	char	f;

	if (format == NULL)
		return (0);
	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*(format + 1))
			f = *(format + 1);
		if (*format == '%')
			len += ft_convert(format, va_arg(ap, char *));
		else
		{
			putchar(*format);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
*/

int		main(void)
{
	wchar_t	*s1 = "Ceci";
	wchar_t	*s2 = "un";
	wchar_t	*s3 = "test";

	printf("%S est %s %s.\n", s1, s2, s3);
	return (0);
}
