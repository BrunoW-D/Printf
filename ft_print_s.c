/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:54:27 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/09 18:57:58 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_print_s(char *str, va_list ap, t_flags *flags)
{
	int		len;

	str = va_arg(ap, char*);
	if (flags->modifier[0] == flags->modifier[1] && flags->modifier[1] == 'l')
		return (0);
	else if (flags->modifier[0] == 'l')
		return (ft_print_ls(str, ap, flags));
	if (flags->options[4] > 0)
		str = ft_strsub(str, 0, flags->options[4]);
	len = ft_strlen(str);
	if (len == 0)
		len = 1;
	return (ft_width(str, len, flags));
}
