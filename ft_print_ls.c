/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:26:53 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/09 18:08:27 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_print_ls(char *ret, va_list ap, t_flags *flags)
{
	wchar_t *ws;
	int	len;

	flags->options[0] += 0;
	ws = va_arg(ap, wchar_t*);
	while (*ws)
	{
		ret = ft_realloc_free(ret, ft_wchar_to_char(*ws));
		ws++;
	}
	len = ft_strlen(ret);
	if (len == 0)
		len = 1;
	return (ft_width(ret, len, flags));
}
