/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:14:49 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/11 16:25:46 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	i = size;
	while (i >= 0)
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

static char	*ft_strdup(const char *src)
{
	int		i;
	char	*cpy;

	i = 0;
	while (src[i])
		i++;
	if ((cpy = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static char	*ft_init_negative(int len, long *nb)
{
	char	*nbr;

	if ((nbr = ft_strnew(len)) == NULL)
		return (NULL);
	nbr[0] = '-';
	*nb *= -1;
	return (nbr);
}

char		*ft_base(int n, int base)
{
	long		nb;
	int			len;
	char		*nbr;

	if (base < 1 || base > 36)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	len = 1;
	while (nb /= base)
		len++;
	nb = n;
	if (n < 0 && ((nbr = ft_init_negative(++len, &nb)) == NULL))
		return (NULL);
	if (n > 0 && ((nbr = ft_strnew(len)) == NULL))
		return (NULL);
	while (nb > 0)
	{
		nbr[--len] = nb % base < 10 ? nb % base + 48 : nb % base + 55;
		nb /= base;
	}
	return (nbr);
}

int			main(void)
{
	puts(ft_base(28, 16));
	puts(ft_base(0, 4));
	puts(ft_base(-33, 16));
	puts(ft_base(-33, 10));
	return (0);
}
