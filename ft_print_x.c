/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:20:34 by bwang-do          #+#    #+#             */
/*   Updated: 2018/03/16 17:43:11 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_x(va_list ap, t_flags *flags)
{
	unsigned int	x;
	char			*ret;

	x = va_arg(ap, unsigned int);
	ret = ft_base(x, 16);
	if (flags->options[0])
		if ((ret = ft_realloc_free(ft_strdup("0x"), ret)) == NULL)
			return (NULL);
	return (ret);
}
