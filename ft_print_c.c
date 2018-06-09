/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:19:37 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/09 18:58:37 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_print_c(char *ret, va_list ap, t_flags *flags)
{
	char	c;

	ret = ft_strnew(1);
	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		return (0);
	else if (flags->modifier[0] == 'l')
		return (ft_print_lc(ret, ap, flags));
	c = va_arg(ap, int);
	ret[0] = c;
	return (ft_width(ret, 1, flags));
}
