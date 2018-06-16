/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:22:25 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/16 19:14:19 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_nchar(char c, size_t n)
{
	char	*str;
	size_t	i;

	if ((str = ft_strnew(n)) == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[n] = 0;
	return (str);
}
