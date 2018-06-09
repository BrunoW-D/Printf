/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:09:41 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/09 18:57:33 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	(*g_p[14]) (char *ret, va_list ap, t_flags *flags);
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

int		ft_print_controller(char c, va_list ap, t_data *data)
{
	int		i;
	char	*str;
	int		ret;

	init_p();
	i = 0;
	str = NULL;
	ret = 0;
	while (i <= 13)
	{
		if (c == g_types[i])
			if ((ret = g_p[i](str, ap, data->flags)) == 0)
				return (0);
		i++;
	}
	if ((data->str = ft_realloc_mem(data->str, str, data->total, ret)) == NULL)
		return (0);
	data->total += ret;
	return (1);
}
