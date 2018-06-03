/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:05:10 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/03 16:49:21 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_width(char *str, int len, t_flags *flags)
{
	int width;

	width = flags->options[3];
	if (width > len)
	{
		if (flags->options[1] == 2)
		{
			if (!(str = ft_realloc_free(ft_nchar('0', width - len), str)))
				return (NULL);
		}
		else if (flags->options[1] == 1)
		{
			if (!(str = ft_realloc_free(str, ft_nchar(' ', width - len))))
				return (NULL);
		}
		else if (flags->options[1] == 0)
		{
			if (!(str = ft_realloc_free(ft_nchar(' ', width - len), str)))
				return (NULL);
		}
	}
	return (str);
}
