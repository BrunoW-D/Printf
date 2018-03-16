/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:44:59 by bwang-do          #+#    #+#             */
/*   Updated: 2018/03/16 17:55:08 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_print_p(va_list ap, t_flags *flags)
{
	void	*p;
	char	*ret;

	flags->options[0] = 0;
	p = va_arg(ap, void*);
	ret = ft_itoa((int)p);
	return (ret);
}