/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:20:23 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/09 19:03:12 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_print_o(char *ret, va_list ap, t_flags *flags)
{
	unsigned long long	o;
	int					len;

	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		o = va_arg(ap, unsigned long long);
	else if (flags->modifier[0] == 'l')
		o = va_arg(ap, unsigned long);
	else if (flags->modifier[0] == 'j')
		o = va_arg(ap, uintmax_t);
	else if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'h')
		o = (unsigned char)va_arg(ap, int);
	else if (flags->modifier[0] == 'h')
		o = (unsigned short)va_arg(ap, unsigned int);
	else if (flags->modifier[0] == 'z')
		o = va_arg(ap, size_t);
	else
		o = va_arg(ap, unsigned int);
	if ((ret = ft_base(o, 8)) == NULL)
		return (0);
	len = ft_strlen(ret);
	if (flags->options[4] > len)
	{
		if ((ret = ft_realloc_free(ft_nchar('0', flags->options[4] - len), ret)) == NULL)
			return (0);
	}
	if (flags->options[0])
		if ((ret = ft_realloc_free(ft_strdup("0"), ret)) == NULL)
			return (0);
	return (ft_width(ret, ft_strlen(ret), flags));
}
