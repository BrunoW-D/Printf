/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:27:24 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/11 16:23:43 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_realloc(const char *str1, const char *str2)
{
	char	*tmp;
	int		i;

	if (!str1 && !str2)
		return (NULL);
	if (!str1 && str2)
		return (str2);
	if (!str2)
		return (str1);
	tmp = ft_strdup(str1);
	if ((str1 = ft_strnew(ft_strlen(str1) + ft_strlen(str2))) == NULL)
		return (NULL);
	str1 = ft_strcpy(str1, tmp);
	str1 = ft_strcat(str1, str2);
	free(tmp);
	return (str1);
}
