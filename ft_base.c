/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:14:49 by bwang-do          #+#    #+#             */
/*   Updated: 2018/05/30 19:48:23 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char	*ft_init_negative(int len, long long *nb)
{
	char	*nbr;

	if ((nbr = ft_strnew(len)) == NULL)
		return (NULL);
	nbr[0] = '-';
	*nb *= -1;
	return (nbr);
}

char		*ft_base(long long n, int base)
{
	long long			nb;
	int					len;
	char				*nbr;
	unsigned int		u;
	unsigned long long	llu;

	u = n;
	llu = n;
	if (base < 1 || base > 35)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	if (base > 10)
	{
		if (n > 2147483647)
			nb = llu;
		else
			nb = u;
	}
	else
		nb = n;
	len = 1;
	while (nb /= base)
		len++;
	if (base > 10)
	{
		if (n > 2147483647)
			nb = llu;
		else
			nb = u;
	}
	else
		nb = n;
	if (nb < 0 && ((nbr = ft_init_negative(++len, &nb)) == NULL))
		return (NULL);
	if (nb > 0 && ((nbr = ft_strnew(len)) == NULL))
		return (NULL);
	while (nb > 0)
	{
		nbr[--len] = nb % base < 10 ? nb % base + 48 : nb % base + 87;
		nb /= base;
	}
	return (nbr);
}
