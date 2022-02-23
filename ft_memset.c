/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:05:16 by wrolanda          #+#    #+#             */
/*   Updated: 2022/02/23 19:56:44 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*memset - fill a byte string with a byte value
DESCRIPTION
	The memset() function writes len bytes of value c (converted to an
	unsigned char) to the string b.*/
#include "./pipex.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	unsigned char	c11[12] = "Hello World";
	unsigned char	c12[12] = "Hello World";

	unsigned char	c21[11] = "1234567890";
	unsigned char	c22[11] = "1234567890";

	printf("STR	['%s']\n", c11);
	memset(c11, '_', 11);
	printf("ORIG	['%s']\n", c11);
	ft_memset(c12, '_', 11);
	printf("NEORIG	['%s']\n\n", c12);

	printf("STR	['%s']\n", c21);
	memset(c21, '1', 5);
	printf("ORIG	['%s']\n", c21);
	ft_memset(c22, '1', 5);
	printf("NEORIG	['%s']\n\n", c22);
// array int

	int	c31[] = {1, 2, 3, 4, 5};
	int	c32[] = {1, 2, 3, 4, 5};
	int i = 0;
	while (i < 5)
	{
		printf("%d, ", c31[i]);
		i++;
	}
	printf("\n\n");
	memset(c31, 1, 2);
	printf("ORIG =	");
	i = 0;
	while (i < 5)
	{
		printf("%d, ", c31[i]);
		i++;
	}
	printf("\n");

	ft_memset(c32, 1, 2);
	printf("NEORIG =");
	i = 0;
	while (i < 5)
	{
		printf("%d, ", c32[i]);
		i++;
	}
	printf("\n");
}*/
