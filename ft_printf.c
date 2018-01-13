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

int        	init_data(t_data data)
{
    int    i;
	t_flags flags;
	
    i = 0;
	data->i = i;
    while (i < 5)
    {
        flags->options[i] = 0;
    }
    flags->modifier[0] = 0;
    flags->modifier[1] = 0;
    data->flags = flags;
	ft_bzero(data->buff, BUFF_SIZE + 1);
	return (data);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	t_data	data;
	int		i;
	
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
				return (NULL);
			ft_bzero(data->buff, BUFF_SIZE + 1);
			i = 0;
		}
		else if (format[data->i] == '\')
		{
			if (format[data->i + 1] == '\' || format[data->i + 1] == 'n' || format[data->i + 1] == 'r'
					|| format[data->i + 1] == 'b'] || format[data->i + 1] == 'v')
				...;
			else if (format[data->i + 1] == 'x' || format[data->i + 1] == 'X')
				...;
			else if (format[data->i + 1] >= '0' && format[data->i + 1] <= '7')
				...;
		}
		else if (format[data->i] == '%')
		{
			if ((str = ft_realloc(str, data->buff)) == NULL)
				return (NULL);
			ft_bzero(data->buff, BUFF_SIZE + 1);
			i = 0;
			if ((str = ft_realloc_free(str, ft_get_flags(format, va_arg(ap, char *), data))) == NULL)
				return (NULL);
		}
		else
			data->buff[i++] = format[(data->i)++];
	}
	if ((str = ft_realloc(str, data->buff)) == NULL)
		return (NULL);
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
