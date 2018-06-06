/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:35:45 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/06 19:39:58 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_data	*init_data(t_data *data)
{
	int		i;
	t_flags	*flags;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	if ((flags = (t_flags*)malloc(sizeof(t_flags))) == NULL)
		return (NULL);
	data->i = 0;
	i = 0;
	while (i < 5)
	{
		flags->options[i] = 0;
		i++;
	}
	flags->modifier[0] = 0;
	flags->modifier[1] = 0;
	data->flags = flags;
	data->str = NULL;
	data->total = 0;
	ft_bzero(data->buff, BUFF_SIZE + 1);
	return (data);
}

t_data	*reset_flags(t_data *data)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		data->flags->options[i] = 0;
		i++;
	}
	data->flags->modifier[0] = 0;
	data->flags->modifier[1] = 0;
	return (data);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_data	*data;
	int		i;

	data = NULL;
	data = init_data(data);
	if (format == NULL)
		return (0);
	va_start(ap, format);
	i = 0;
	while (format[data->i])
	{
		if (i == BUFF_SIZE)
		{
			if ((data->str = ft_realloc_mem(data->str, data->buff, data->total, ft_strlen(data->buff))) == NULL)
				return (0);
			data->total += BUFF_SIZE;
			ft_bzero(data->buff, BUFF_SIZE + 1);
			i = 0;
		}
		else if (format[data->i] == '%')
		{
			if (format[(data->i) + 1])
			{
				if ((data->str = ft_realloc_mem(data->str, data->buff, data->total, ft_strlen(data->buff))) == NULL)
					return (0);
				data->total += ft_strlen(data->buff);
				ft_bzero(data->buff, BUFF_SIZE + 1);
				i = 0;
				if (ft_get_flags(format, ap, data) == 0)
					return (0);
				data = reset_flags(data);
			}
			else
				(data->i)++;
		}
		else
			data->buff[i++] = format[(data->i)++];
	}
	if ((data->str = ft_realloc_mem(data->str, data->buff, data->total, ft_strlen(data->buff))) == NULL)
		return (0);
	data->total += ft_strlen(data->buff);
	va_end(ap);
	write(1, data->str, data->total);
	return (data->total);
}
