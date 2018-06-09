/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:20:34 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/09 19:03:48 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_print_x(char *ret, va_list ap, t_flags *flags)
{
	unsigned long long	x;
	int					len;

	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		x = va_arg(ap, unsigned long long);
	else if (flags->modifier[0] == 'l')
		x = va_arg(ap, unsigned long);
	else if (flags->modifier[0] == 'j')
		x = va_arg(ap, uintmax_t);
	else if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'h')
		x = (unsigned char)va_arg(ap, int);
	else if (flags->modifier[0] == 'h')
		x = (unsigned short)va_arg(ap, unsigned int);
	else if (flags->modifier[0] == 'z')
		x = va_arg(ap, size_t);
	else
		x = va_arg(ap, unsigned int);
	if (x == 0 && flags->options[4] == -1)
		ret = (ft_strdup(""));
	else if ((ret = ft_base(x, 16)) == NULL)
		return (0);
	len = ft_strlen(ret);
	if (flags->options[0] && ret[0] != '0')
	{
		if (flags->options[1] == 2)
		{
			if ((ft_width(ret, len + 2, flags)) == 0)
				return (0);
		}
		if ((ret = ft_realloc_free(ft_strdup("0x"), ret)) == NULL)
			return (0);
		if (flags->options[1] != 2)
			return (ft_width(ret, len + 2, flags));
	}
	else
		return (ft_width(ret, len, flags));
}
