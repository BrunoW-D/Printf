/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_to_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:39:51 by bwang-do          #+#    #+#             */
/*   Updated: 2018/01/04 18:48:22 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>

void	ft_wchar_to_char(wchar_t wc)
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
		str[0] = (char)((wc >> 8) & 0xff);
		str[1] = (char)(wc & 0xff);
	}
	else if (wc <= 0xffff)
	{
		str[0] = (char)((wc >> 16) & 0xff);
		str[1] = (char)((wc >> 8) & 0xff);
		str[2] = (char)(wc & 0xff);
	}
	else if (wc <= 0x10ffff)
	{
		str[0] = (char)((wc >> 24) & 0xff);
		str[1] = (char)((wc >> 16) & 0xff);
		str[2] = (char)((wc >> 8) & 0xff);
		str[3] = (char)(wc & 0xff);
	}
	write (1, str, strlen(str));
}

int		main(void)
{
	wchar_t wc = L'\x1234';

	ft_wchar_to_char(wc);
}
