/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:19:37 by bwang-do          #+#    #+#             */
/*   Updated: 2018/03/14 18:04:02 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_c(va_list ap, t_flags *flags)
{
	char	*ret;
	char	c;

	ret = ft_strnew(1);
	c = va_arg(ap, int);
	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		return (NULL);
	else if (flags->modifier[0] == 'l')
		return (ft_print_lc(ap, flags));
	ret[0] = c;
	return (ret);
}
