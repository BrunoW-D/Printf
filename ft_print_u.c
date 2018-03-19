/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:21:11 by bwang-do          #+#    #+#             */
/*   Updated: 2018/03/19 15:25:34 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_u(va_list ap, t_flags *flags)
{
	unsigned long long int	n;
	char					*ret;
	int						len;

	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		n = va_arg(ap, unsigned long long int);
	else if (flags->modifier[0] == 'l')
		n = va_arg(ap, unsigned long int);
	else if (flags->modifier[0] == 'h')
		n = (short)va_arg(ap, unsigned int);
	else
		n = va_arg(ap, unsigned int);
	if ((ret = ft_utoa(n)) == NULL)
		return (NULL);
	len = ft_strlen(ret);
	if (flags->options[4] > len)
	{
		if ((ret = ft_realloc_free(ft_nchar('0', flags->options[4] - len), ret)) == NULL)
			return (NULL);
	}
	if (flags->options[1] == 1)
	{
		if ((ret = ft_realloc_free(ft_nchar('+', 1), ret)) == NULL)
			return (NULL);
	}
	return (ret);
}
