/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:17:01 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/09 18:14:14 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define BUFF_SIZE 4
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

# include <stdio.h>

typedef struct	s_flags
{
	int			options[5];
	char		modifier[2];
}				t_flags;

typedef struct	s_data
{
	t_flags		*flags;
	int			i;
	char		buff[BUFF_SIZE + 1];
	char		*str;
	int			total;
}				t_data;

void			ft_bzero(void *str, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strcat(char *dest, const char *src);
int				ft_isdigit(int c);
char			*ft_strnew(size_t size);
void			ft_putchar(char c);
void			ft_putstr(char const *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);

char			*new_itoa(long long n);
char			*ft_utoa(unsigned long long n);
char			*ft_strlower(char *str);
char			*ft_strupper(char *str);

int				ft_get_flags(const char *format, va_list ap, t_data *data);
int				ft_print_controller(char c, va_list ap, t_data *data);
char			*ft_nchar(char c, size_t n);
char			*ft_realloc(char *str1, const char *str2);
char			*ft_realloc_free(char *str1, char *str2);
char			*ft_realloc_mem(char *str1, char *str2, int len1, int len2);
char			*ft_memdup(const char *src, int len);
char			*ft_base(long long n, int base);
char			*ft_wchar_to_char(wchar_t wc);
int				ft_printf(const char *format, ...);
int				ft_width(char *str, int len, t_flags *flags);

int				ft_print_c(char *str, va_list ap, t_flags *flags);
int				ft_print_lc(char *str, va_list ap, t_flags *flags);
int				ft_print_s(char *str, va_list ap, t_flags *flags);
int				ft_print_ls(char *str, va_list ap, t_flags *flags);
int				ft_print_d(char *str, va_list ap, t_flags *flags);
int				ft_print_ld(char *str, va_list ap, t_flags *flags);
int				ft_print_o(char *str, va_list ap, t_flags *flags);
int				ft_print_lo(char *str, va_list ap, t_flags *flags);
int				ft_print_x(char *str, va_list ap, t_flags *flags);
int				ft_print_lx(char *str, va_list ap, t_flags *flags);
int				ft_print_p(char *str, va_list ap, t_flags *flags);
int				ft_print_u(char *str, va_list ap, t_flags *flags);
int				ft_print_lu(char *str, va_list ap, t_flags *flags);

#endif
