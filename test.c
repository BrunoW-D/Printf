/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:50:16 by bwang-do          #+#    #+#             */
/*   Updated: 2017/12/06 14:13:43 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>

int main(void)
{
	char *str = "Hello world !";
	int	n = 32;
	wchar_t *wstr = (wchar_t*)malloc(sizeof(wchar_t) * 1);
	wstr[0] = 0xC9;

	printf("str = %s, n = %d\n", str, n);
	printf("s =  %s\n", str);
	printf("S = %S\n", wstr);
	printf("p = %p\n", &str);
	printf("d = %d\n", n);
	printf("D = %D\n", n);
	printf("i = %i\n", n);
	printf("o = %o\n", n);
	printf("O = %O\n", n);
	printf("u = %u\n", n);
	printf("U = %U\n", n);
	printf("x = %x\n", n);
	printf("X = %X\n", n);
	printf("c = %c\n", str[0]);
	printf("C = %C\n", str[0]);
	free(wstr);
	return (0);
}
