/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:30:09 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/03 16:55:55 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_lc(va_list ap, t_flags *flags)
{
	char	*ret;
	wchar_t	wc;

	(flags->options[0]) += 0;
	wc = va_arg(ap, wchar_t);
	ret = NULL;
	ret = ft_realloc_free(ret, ft_wchar_to_char(wc));
	return (ft_width(ret, ft_strlen(ret), flags));
}
