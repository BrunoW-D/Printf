/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:19:47 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/03 19:57:06 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_d(va_list ap, t_flags *flags)
{
	long long	n;
	char		*ret;
	int			len;
	int			i;

	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		n = va_arg(ap, long long);
	else if (flags->modifier[0] == 'l')
		n = va_arg(ap, long);
	else if (flags->modifier[0] == 'j')
		n = va_arg(ap, intmax_t);
	else if (flags->modifier[0] == 'z')
		n = va_arg(ap, ssize_t);
	else if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'h')
		n = (char)va_arg(ap, int);
	else if (flags->modifier[0] == 'h')
		n = (short)va_arg(ap, int);
	else
		n = va_arg(ap, int);
	if ((ret = new_itoa(n)) == NULL)
		return (NULL);
	len = ft_strlen(ret);
	if (n < 0)
		len--;
	if (flags->options[4] > len)
	{
		if ((ret = ft_realloc_free(ft_nchar('0', flags->options[4] - len), ret)) == NULL)
			return (NULL);
	}
	len = ft_strlen(ret);
	if (flags->options[2] == 1 && n >= 0)
	{
		if (flags->options[1] == 2)
		{
			if ((ret = ft_width(ret, len + 1, flags)) == NULL)
				return (NULL);
		}
		if ((ret = ft_realloc_free(ft_strdup("+"), ret)) == NULL)
			return (NULL);
		if (flags->options[1] != 2)
			ret = ft_width(ret, len + 1, flags);
	}
	else if (flags->options[2] == 2 && n >= 0)
	{
		if ((ret = ft_realloc_free(ft_strdup(" "), ret)) == NULL)
			return (NULL);
		ret = ft_width(ret, len + 1, flags);
	}
	else
		ret = ft_width(ret, len, flags);
	if (ret[0] == '0' && n < 0)
	{
		i = 0;
		while (ret[i] == '0')
			i++;
		ret[i] = '0';
		ret[0] = '-';
	}
	return (ret);
}
