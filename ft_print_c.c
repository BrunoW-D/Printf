/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:19:37 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/16 19:10:38 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_c(va_list ap, t_flags *flags)
{
	char	*ret;
	char	c;

	if ((ret = ft_strnew(1)) == NULL)
		return (NULL);
	if (flags->modifier[0] == 'l')
		return (ft_print_lc(ap, flags));
	c = va_arg(ap, int);
	ret[0] = c;
	return (ft_width(ret, 1, flags));
}
