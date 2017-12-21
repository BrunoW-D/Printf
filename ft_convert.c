/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:46:49 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/11 16:23:56 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		is_type_flag(const char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'D' || c == 'i' || c == 'o'
			|| c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
			|| c == 'c' || c == 'C')
		return (1);
	else
		return (0);
}

int		is_modif(const char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	else
		return (0);
}

int		init_flags(t_flags flags)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		flags->options[i] = 0;
	}
	flags->modifier[0] = 0;
	flags->modifier[1] = 0;
	return (flags);
}

int		is_format_flag(const char c)
{
	if (c == '#' || c == '-' || c == '+' || c == ' ' || c == '0')
		return (1);
	else
		return (0);
}

char	*ft_convert(const char *format, va_list ap)
{
	t_flags	flags;

	flags = init_flags(flags);
	while (is_format_flag(*format))
	{
		if (*format == '#')
			flags->options[0] = 1;
		else if (*format == '-')
			flags->options[1] = 1;
		else if (*format == '+')
			flags->options[2] = 1;
		else if (*format == ' ' && !flags->options[2])
			flags->options[2] = 2;
		else if (*format == '0' && !flags->options[1])
			flags->options[1] = 2;
		format++;
	}
	while (ft_isdigit(*format))
	{
		flags->options[3] *= 10;
		flags->options[3] += *format;
		format++;
	}
	if (*format == '.')
	{
		if (ft_isdigit(*++format))
			while (ft_isdigit(*format))
			{
				flags->options[4] *= 10;
				flags->options[4] += *format;
				format++;
			}
		else
			return (NULL);
	}
	if (is_modif(*format))
	{
		flags->modifier[0] = *format;
		if ((*format == 'h' && *format  + 1 == 'h')
				|| (*format == 'l' && *format + 1 == 'l'))
			flags->modifier[1] = *format++;
		format++;
	}
	if (is_type_flag(*format) && *format + 1 == '\0')
		return (ft_print_controller(*format, ap, flags));
	else
		return (NULL);
}
