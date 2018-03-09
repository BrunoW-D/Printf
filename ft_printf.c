/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:35:45 by bwang-do          #+#    #+#             */
/*   Updated: 2018/03/09 18:16:29 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_data	*init_data(t_data *data)
{
	int		i;
	t_flags	*flags;

	i = 0;
	data->i = i;
	flags = NULL;
	while (i < 5)
	{
		flags->options[i] = 0;
	}
	flags->modifier[0] = 0;
	flags->modifier[1] = 0;
	data->flags = flags;
	data->total = 0;
	ft_bzero(data->buff, BUFF_SIZE + 1);
	return (data);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	t_data	*data;
	int		i;

	printf("k\n");
	data = NULL;
	data = init_data(data);
	if (format == NULL)
		return (0);
	va_start(ap, format);
	str = NULL;
	i = 0;
	while (format[data->i])
	{
		if (i == BUFF_SIZE)
		{
			if ((str = ft_realloc(str, data->buff)) == NULL)
				return (0);
			ft_bzero(data->buff, BUFF_SIZE + 1);
			i = 0;
		}
		else if (format[data->i] == '%')
		{
			if ((str = ft_realloc(str, data->buff)) == NULL)
				return (0);
			ft_bzero(data->buff, BUFF_SIZE + 1);
			i = 0;
			if ((str = ft_realloc_free(str, ft_get_flags(format, ap, data))) == NULL)
				return (0);
		}
		else
			data->buff[i++] = format[(data->i)++];
	}
	if ((str = ft_realloc(str, data->buff)) == NULL)
		return (0);
	va_end(ap);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
