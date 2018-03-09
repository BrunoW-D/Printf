/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_to_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:39:51 by bwang-do          #+#    #+#             */
/*   Updated: 2018/03/09 15:31:22 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_wchar_to_char(wchar_t wc)
{
	char	str[5];
	int		i;

	i = 0;
	while (i < 5)
	{
		str[i] = '\0';
		i++;
	}
	if (wc <= 0x7f)
		str[0] = (char)wc;
	else if (wc <= 0x7ff)
	{
		str[0] = (char)(wc >> 6 | 0xc0);
		str[1] = (char)((wc & 0x3f) | 0x80);
	}
	else if (wc <= 0xffff)
	{
		str[0] = (char)(wc >> 12 | 0xe0);
		str[1] = (char)((wc >> 6 & 0x3f) | 0x80);
		str[2] = (char)((wc & 0x3f) | 0x80);
	}
	else if (wc <= 0x10ffff)
	{
		str[0] = (char)(wc >> 18 | 0xf0);
		str[1] = (char)((wc >> 12 & 0x3f) | 0x80);
		str[2] = (char)((wc >> 6 & 0x3f) | 0x80);
		str[3] = (char)((wc & 0x3f) | 0x80);
	}
	return(ft_strdup(str));
}
