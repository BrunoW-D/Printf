/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:19:19 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/06 19:26:47 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_realloc_free(char *str1, char *str2)
{
	char	*tmp;

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
	free(str2);
	str2 = NULL;
	return (str1);
}

char	*ft_realloc_mem(char *mem1, char *mem2, int len1, int len2)
{
	char	*tmp;

	if (len1 == 0 && len2 == 0)
		return (NULL);
	else if (len1 == 0)
		return (mem2);
	else if (len2 == 0)
		return (mem1);
	tmp = ft_memdup(mem1, len1);
	if ((mem1 = ft_memalloc(len1 + len2)) == NULL)
		return (NULL);
	mem1 = ft_memcpy(mem1, tmp, len1);
	mem1 = ft_memcpy(mem1 + len1, mem2, len2);
	free(tmp);
	free(mem2);
	mem2 = NULL;
	return (mem1);
}
