/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:17:01 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/11 16:27:09 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_flags
{
	int			options[5];
	char		modifier[2];
}				t_flags;

typedef struct	s_data
{
	t_flags		flags;
	int		i;
}		t_data;

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strcat(char *dest, const char *src);
int				ft_isdigit(int c);
char			*ft_strnew(size_t size);
void			ft_putchar(char c);
void			ft_putstr(char const *str);
char			*ft_strndup(const char *src, size_t n);

#endif
