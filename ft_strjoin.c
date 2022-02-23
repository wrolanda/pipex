/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:50:16 by wrolanda          #+#    #+#             */
/*   Updated: 2022/02/23 20:19:44 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.

PARAMETERS
#1. The prefix string.
#2. The suffix string.
*/
#include "./pipex.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = (void *)malloc(size * count);
	if (p == (void *)0)
		return ((void *)0);
	ft_bzero(p, count * size);
	return (p);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res_dst;
	size_t	res_src;

	i = 0;
	res_dst = ft_strlen(dst);
	res_src = ft_strlen(src);
	j = res_dst;
	if (dstsize <= 0)
		return (res_src + dstsize);
	while (src[i] && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if (dstsize != 0 && res_dst <= dstsize)
		dst[j] = '\0';
	if (dstsize < res_dst)
		return (res_src + dstsize);
	else
		return (res_dst + res_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	newstr = ft_calloc(sizeof(char), i + 1);
	if (newstr == NULL)
		return (NULL);
	j = ft_strlcat(newstr, s1, i + 1) + ft_strlcat(newstr, s2, i + 1);
	j = 0;
	return (newstr);
}
