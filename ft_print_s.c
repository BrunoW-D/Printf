/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:54:27 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/11 16:24:59 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_print_s(va_list ap, t_flags *flags)
{
	int		i;
	char	*str;
	char	*ret;

	str = va_arg(ap, char*);
	if (flags->modifier[0] == flags->modifier[1] == 'l')
		return (NULL);
	else if (flags->modifier[0] == 'l')
		return (ft_print_ss(ap, flags);
	i = 0;
	while (str[i] && i < flags->options[4])
		i++;
	ret = ft_strsub(str, 0, i);
	return (ret);
}
