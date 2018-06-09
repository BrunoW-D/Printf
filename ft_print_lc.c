/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:30:09 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/09 18:13:04 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_print_lc(char *ret, va_list ap, t_flags *flags)
{
	wchar_t	wc;
	int	len;

	(flags->options[0]) += 0;
	wc = va_arg(ap, wchar_t);
	ret = NULL;
	if ((ret = ft_realloc_free(ret, ft_wchar_to_char(wc))) == NULL)
		return (0);
	len = ft_strlen(ret);
	if (len == 0)
		len = 1;
	return (ft_width(ret, len, flags));
}
