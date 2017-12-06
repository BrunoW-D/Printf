/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:46:49 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/06 13:32:42 by bwang-do         ###   ########.fr       */
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

int		is_num(const char c)
{
	if (c >= '0' && c <= '9')
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

int		init_flags(int flags[5])
{
	int	i;

	i = 0;
	while (i < 5)
	{
		flags[i] = 0;
	}
	return (flags);
}

int		ft_convert(const char *format, va_list ap)
{
	int		*flags[5];
	char	modif;

	flags = init_flags(flags);
	modif = 0;
	while (!is_num(*format) && *format != '.' && !is_modif(*format))
	{
		if (*format == '#')
			flags[0] == 1;
		else if (*format == '-')
			flags[1] = 1;
		else if (*format == '+')
			flags[2] = 1;
		else if (*format == ' ' && !flags[2])
			flags[2] = 2;
		else if (*format == '0' && !flags[1])
			flags[1] = 2;
		format++;
	}
	while (!is_type_flag(*format) && *format != '.' && !is_modif(*format))
	{
		flags[3]++;
		format++;
	}
	if (*format == '.')
		while (!is_type_flag(*format) && !is_modif(*format))
		{
			flags[4]++;
			format++;
		}
	if (is_modif(*format))
	{
		if ((*format == 'h' && *format  + 1 == 'h')
				|| (*format == 'l' && *format + 1 == 'l'))
			format++;
		modif = *format++;
	}
	if (is_type_flag(*format))
		return (ft_print_controller(*format, ap, flags, modif));
	else
		return (0);
}
