/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:46:49 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/04 15:00:02 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_type_flag(const char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'D' || c == 'i' || c == 'o'
			|| c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
			|| c == 'c' || c == 'C')
		return (1);
	else
		return (0);
}

int		ft_convert(const char *format, va_list ap)
{
	while (*format)
	{
		if (*format == '-');
		if (*format == '+');
		if (*format == '0');
		if (*format == ' ');
		if (*format == '#');
		...
		if (is_type_flag(*format))
			return (ft_print_controller(*format, ap);
		format++;
	}
	return (0);
}
