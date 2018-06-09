/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:05:10 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/09 18:07:34 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_width(char *str, int len, t_flags *flags)
{
	int 	width;
	int		ret;

	width = flags->options[3];
	if (width > len)
	{
		if (!str[0])
			ret = width + 1;
		else
			ret = width > len ? width : len;
		if (flags->options[1] == 2)
		{
			if ((str = ft_realloc_mem(ft_nchar('0', width - len), str, width - len, len)) == NULL)
				return (0);
		}
		else if (flags->options[1] == 1)
		{
			if ((str = ft_realloc_mem(str, ft_nchar(' ', width - len), len, width - len)) == NULL)
				return (0);
		}
		else if (flags->options[1] == 0)
		{
			if ((str = ft_realloc_mem(ft_nchar(' ', width - len), str, width - len, len)) == NULL)
				return (0);
		}
	}
	return (ret);
}
