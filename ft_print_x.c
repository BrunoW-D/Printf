/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:20:34 by bwang-do          #+#    #+#             */
/*   Updated: 2018/05/30 19:47:54 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_x(va_list ap, t_flags *flags)
{
	unsigned long long	x;
	char				*ret;

	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		x = va_arg(ap, unsigned long long);
	else if (flags->modifier[0] == 'l')
		x = va_arg(ap, unsigned long);
	else if (flags->modifier[0] == 'h')
		x = (unsigned short)va_arg(ap, unsigned int);
	else
		x = va_arg(ap, unsigned int);
	ret = ft_base(x, 16);
	if (flags->options[0])
	{
		if ((ret = ft_realloc_free(ft_strdup("0x"), ret)) == NULL)
			return (NULL);
	}
	return (ret);
}
