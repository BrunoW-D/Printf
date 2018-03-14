/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:26:53 by bwang-do          #+#    #+#             */
/*   Updated: 2018/03/14 17:30:40 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_ls(va_list ap, t_flags *flags)
{
	wchar_t *ws;
	char	*ret;

	flags->options[0] += 0;
	ws = va_arg(ap, wchar_t*);
	while (*ws)
	{
		ret = ft_realloc_free(ret, ft_wchar_to_char(*ws));
		ws++;
	}
	/* Precision pour wchar ??? */
	return (ret);
}
