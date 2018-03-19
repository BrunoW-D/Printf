/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:18:57 by bwang-do          #+#    #+#             */
/*   Updated: 2018/03/19 17:17:04 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char	*ft_init_negative(int len, long long *nb)
{
	char				*str;

	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	str[0] = '-';
	/*
	if ((**(long long**)p) == -9223372036854775808)
	{
		u = 9223372036854775808U;
		*p = &u;
	}
	else
	*/
	*nb *= -1;
	return (str);
}

char		*new_itoa(long long n)
{
	char		*str;
	long long	nb;
	int			len;
	//void		*p;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	len = 1;
	while (nb /= 10)
		len++;
	//p = &nb;
	nb = n;
	if (n < 0)
	{
		if ((str = ft_init_negative(++len, &nb)) == NULL)
			return (NULL);
	}
	else if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	while (len-- > 0 && nb)
	{
		str[len] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}
