/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:20:23 by bwang-do          #+#    #+#             */
/*   Updated: 2018/03/07 18:20:24 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_o(va_list ap, t_flags *flags)
{
	unsigned int	o;
	char			*ret;

	o = va_arg(ap, unsigned int);
	ret = ft_base(o, 8);
	if (flags->options[0])
		if ((ret = ft_realloc_free("0", ret)) == NULL)
			return (NULL);
	return (ret);
}
