/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:09:41 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/06 19:50:30 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char	*(*g_p[14]) (va_list ap, t_flags *flags);
static char	*g_types = "sSpdDioOuUxXcC";

void	init_p(void)
{
	g_p[0] = ft_print_s;
	g_p[1] = ft_print_ls;
	g_p[2] = ft_print_p;
	g_p[3] = ft_print_d;
	g_p[4] = ft_print_ld;
	g_p[5] = ft_print_d;
	g_p[6] = ft_print_o;
	g_p[7] = ft_print_lo;
	g_p[8] = ft_print_u;
	g_p[9] = ft_print_lu;
	g_p[10] = ft_print_x;
	g_p[11] = ft_print_lx;
	g_p[12] = ft_print_c;
	g_p[13] = ft_print_lc;
}

char	*ft_print_controller(char c, va_list ap, t_data *data)
{
	int		i;
	char	*str;

	init_p();
	i = 0;
	str = NULL;
	while (i <= 13)
	{
		if (c == g_types[i])
			str = g_p[i](ap, data->flags);
		i++;
	}
	if ((data->str = ft_realloc_mem(data->str, str, data->total, ???)) == NULL)
		return (NULL);
	data->total += ???;
	return (str);
}
