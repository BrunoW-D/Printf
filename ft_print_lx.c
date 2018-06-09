/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:34:19 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/09 19:04:34 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_print_lx(char *ret, va_list ap, t_flags *flags)
{

	ft_print_x(ret, ap, flags);
	ret = ft_strupper(ret);
	if (flags->options[0])
	{
		ret[1] = 'X';
	}
	return (ft_strlen(ret));
}
