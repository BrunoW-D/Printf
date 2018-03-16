/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:19:47 by bwang-do          #+#    #+#             */
/*   Updated: 2018/03/16 17:37:35 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_d(va_list ap, t_flags *flags)
{
	long long int	n;
	char			*ret;
	int				len;

	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		n = va_arg(ap, long long int);
	else if (flags->modifier[0] == 'l')
		n = va_arg(ap, long int);
	else if (flags->modifier[0] == 'h')
		n = (short)va_arg(ap, int);
	else
		n = va_arg(ap, int);
	if ((ret = ft_itoa(n)) == NULL)
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
