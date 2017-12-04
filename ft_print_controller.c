/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:09:41 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/04 12:52:15 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int		ft_print_controller(char c, va_list ap)
{
	if (c == s)
		return (ft_print_s(ap));
	else if (c == S)
		return (ft_print_ss(ap));
	else if (c == p)
		return (ft_print_p(ap));
	else if (c == d)
		return (ft_print_d(ap));
	else if (c == D)
		return (ft_print_dd(ap));
	else if (c == i)
		return (ft_print_i(ap));
	else if (c == o)
		return (ft_print_o(ap));
	else if (c == O)
		return (ft_print_oo(ap));
	else if (c == u)
		return (ft_print_u(ap));
	else if (c == U)
		return (ft_print_uu(ap));
	else if (c == x)
		return (ft_print_x(ap));
	else if (c == X)
		return (ft_print_xx(ap));
	else if (c == c)
		return (ft_print_c(ap));
	else if (c == C)
		return (ft_print_cc(ap));
}
