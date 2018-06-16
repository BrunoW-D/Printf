/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:21:51 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/16 18:40:16 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		is_type_flag(const char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D'
			|| c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U'
			|| c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (1);
	else
		return (0);
}

int		get_num(const char *format, t_data *data)
{
	int n;

	n = 0;
	if (format[data->i] == '.')
	{
		(data->i)++;
		if (format[data->i] < '1' || format[data->i] > '9')
		{
			if (format[data->i] != '0')
				(data->i)--;
			return (-1);
		}
	}
	while (format[data->i] >= '0' && format[data->i] <= '9')
	{
		n *= 10;
		n += format[data->i] - 48;
		(data->i)++;
	}
	(data->i)--;
	return (n);
}

void	get_modifier(const char *format, t_data *data)
{
	if (data->flags->modifier[0] == 'h' && format[data->i] == 'h')
		data->flags->modifier[1] = 'h';
	else if (data->flags->modifier[0] == 'l' && format[data->i] == 'l')
		data->flags->modifier[1] = 'l';
	else if (format[data->i] > data->flags->modifier[0])
	{
		data->flags->modifier[0] = format[data->i];
		data->flags->modifier[1] = 0;
	}
	else if (data->flags->modifier[0] == 0)
		data->flags->modifier[0] = format[data->i];
}

char	*ft_get_flags(const char *format, va_list ap, t_data *data)
{
	int		i;

	i = data->i;
	(data->i)++;
	while (format[data->i])
	{
		if (format[data->i] == '#')
			data->flags->options[0] = 1;
		else if (format[data->i] == '-')
			data->flags->options[1] = 1;
		else if (format[data->i] == '+')
			data->flags->options[2] = 1;
		else if (format[data->i] == ' ')
		{
			if (!data->flags->options[2])
				data->flags->options[2] = 2;
		}
		else if (format[data->i] == '0')
		{
			if (!data->flags->options[1])
				data->flags->options[1] = 2;
		}
		else if (format[data->i] >= '1' && format[data->i] <= '9')
			data->flags->options[3] = get_num(format, data);
		else if (format[data->i] == '.')
			data->flags->options[4] = get_num(format, data);
		else if (format[data->i] == 'h' || format[data->i] == 'l'
				|| format[data->i] == 'j' || format[data->i] == 'z')
			get_modifier(format, data);
		else if (is_type_flag(format[data->i]))
			return (ft_print_controller(format[(data->i)++], ap, data));
		else if (format[data->i] == '%')
		{
			(data->i)++;
			return (ft_width(ft_strdup("%"), 1, data->flags));
		}
		else
			return (NULL);
		//return (ft_width(ft_strsub(format, i, data->i - i), (data->i)++ - i, data->flags));
		(data->i)++;
	}
	return (NULL);
}
