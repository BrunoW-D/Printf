/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:20:23 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/03 19:44:27 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_o(va_list ap, t_flags *flags)
{
	unsigned int	o;
	char			*ret;
	int				len;

	o = va_arg(ap, unsigned int);
	ret = ft_base(o, 8);
	len = ft_strlen(ret);
	if (flags->options[4] > len)
	{
		if ((ret = ft_realloc_free(ft_nchar('0', flags->options[4] - len), ret)) == NULL)
			return (NULL);
	}
	if (flags->options[0])
		if ((ret = ft_realloc_free(ft_strdup("0"), ret)) == NULL)
			return (NULL);
	return (ft_width(ret, ft_strlen(ret), flags));
}
