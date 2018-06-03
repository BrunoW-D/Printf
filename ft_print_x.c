/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:20:34 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/03 18:52:37 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_x(va_list ap, t_flags *flags)
{
	unsigned long long	x;
	char				*ret;
	int					len;

	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		x = va_arg(ap, unsigned long long);
	else if (flags->modifier[0] == 'l')
		x = va_arg(ap, unsigned long);
	else if (flags->modifier[0] == 'h')
		x = (unsigned short)va_arg(ap, unsigned int);
	else
		x = va_arg(ap, unsigned int);
	ret = ft_base(x, 16);
	len = ft_strlen(ret);
	if (flags->options[0] && ret[0] != '0')
	{
		if (flags->options[1] == 2)
		{
			if ((ret = ft_width(ret, len + 2, flags)) == NULL)
				return (NULL);
		}
		if ((ret = ft_realloc_free(ft_strdup("0x"), ret)) == NULL)
			return (NULL);
		if (flags->options[1] != 2)
			ret = ft_width(ret, len + 2, flags);
	}
	else
		ret = ft_width(ret, len, flags);
	return (ret);
}
