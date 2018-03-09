/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:30:09 by bwang-do          #+#    #+#             */
/*   Updated: 2018/03/09 17:46:57 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_lc(va_list ap, t_flags *flags)
{
	char	*ret;
	wchar_t	wc;

	flags = flags;
	wc = va_arg(ap, wchar_t);
	ret = NULL;
	ret = ft_realloc_free(ret, ft_wchar_to_char(wc));
	return (ret);
}
