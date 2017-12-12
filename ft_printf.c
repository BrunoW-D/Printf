/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:35:45 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/11 16:27:00 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	//char	f;
	char	*str;

	if (format == NULL)
		return (0);
	len = 0;
	va_start(ap, format);
	while (*format)
	{
		//if (*(format + 1))
		//	f = *(format + 1);
		if (*format == '%')
			str = ft_realloc(str, ft_convert(format, va_arg(ap, char *)));
		else
			str = ft_realloc(str, *format);
		format++;
	}
	va_end(ap);
	ft_putstr(str);
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
