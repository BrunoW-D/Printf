/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:34:19 by bwang-do          #+#    #+#             */
/*   Updated: 2018/05/30 19:52:31 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_lx(va_list ap, t_flags *flags)
{
	char	*ret;

	ret = ft_print_x(ap, flags);
	ret = ft_strupper(ret);
	if (flags->options[0])
	{
		ret[1] = 'X';
	}
	return (ret);
}
