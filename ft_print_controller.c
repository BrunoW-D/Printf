/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:09:41 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/11 16:24:28 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char	(*g_p[14]) (va_list ap, t_flags flags);
static char	*g_types = "sSpdDioOuUxXcC";

void	init_p()
{
	g_p[0] = ft_print_s;
	g_p[1] = ft_print_ss;
	g_p[2] = ft_print_p;
	g_p[3] = ft_print_d;
	g_p[4] = ft_print_dd;
	g_p[5] = ft_print_i;
	g_p[6] = ft_print_o;
	g_p[7] = ft_print_oo;
	g_p[8] = ft_print_u;
	g_p[9] = ft_print_uu;
	g_p[10] = ft_print_x;
	g_p[11] = ft_print_xx;
	g_p[12] = ft_print_c;
	g_p[13] = ft_print_cc;
}

char	*ft_print_controller(char c, va_list ap, t_data data)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	while (g_types[i])
	{
		if (c == g_types[i])
			str = g_p[i](ap, data->flags);
		i++;
	}
	if ((len = ft_strlen(str)) < flags->options[3])
	{
		i = 0;
		if (data->flags->options[1] == 2)
		{
			while (i < len)
			{
				if (i == BUFF_SIZE)
				{
					if ((str = ft_realloc_free(data->buff, str)) = NULL)
						return (NULL);
					ft_bzero(data->buff, BUFF_SIZE + 1);
					i = 0;
					len -= i;
				}
				data->buff[i++] = '0';
			}
			if ((str = ft_realloc_free(data->buff, str)) == NULL)
				return (NULL);
		}
		else if (data->flags->options[1] == 1)
		{
			while (i < len)
			{
				if (i == BUFF_SIZE)
				{
					if ((str = ft_realloc(str, data->buff)) == NULL)
						return (NULL);
					ft_bzero(data->buff, BUFF_SIZE + 1);
					i = 0;
					len -= i;
				}
				data->buff[i++] = ' ';
				if ((str = ft_realloc(str, data->buff)) == NULL)
					return (NULL);
			}
		}
		else if (data->flags->options[1] == 0)
		{
			while (i < len)
			{
				if (i == BUFF_SIZE)
				{
					if ((str = ft_realloc_free(data->buff, str)) == NULL)
						return (NULL);
					ft_bzero(data->buff, BUFF_SIZE + 1);
					i = 0;
					len -= i;
				}
				data->buff[i++] = ' ';
			}
			if ((str = ft_realloc_free(data->buff, str)) == NULL)
				return (NULL);
		}
	}
	return (str);
}
