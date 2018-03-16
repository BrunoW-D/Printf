/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 17:34:33 by bwang-do          #+#    #+#             */
/*   Updated: 2018/03/16 17:54:29 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		main(void)
{
	char			*str = "World";
	int				len;
	unsigned int	n = 19;

	len = ft_printf("Hello %7s %c\n", str, '!');
	ft_printf("len = %-5.3d\n", len);
	ft_printf("%#o\n", n);
	ft_printf("%#x\n", n);
	ft_printf("%p\n", &n);
	return (0);
}
