/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:45:30 by wrolanda          #+#    #+#             */
/*   Updated: 2022/02/23 20:18:19 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must be
ended by a NULL pointer.

PARAMETERS
#1. The string to be split.
#2. The delimiter character.
*/

#include "./pipex.h"
#include <stddef.h>

static int	ft_words_count(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			k++;
		}
	}
	return (k);
}

static int	ft_word_len(char const *s, char c, int i)
{
	int	k;

	k = 0;
	if (s[i] != c && s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			k++;
		}
	}
	return (k);
}

static void	ft_frees(char **res, int q)
{
	q--;
	while (q >= 0)
	{
		free(res[q]);
		q--;
	}
	free(res);
}

static char	**ft_wordprint(char **res, char const *s, char c, int q)
{
	int	k;
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			res[q] = (char *)malloc(sizeof(char) * (ft_word_len(s, c, i) + 1));
			if (res[q] == NULL)
			{
				ft_frees (res, q);
				return (NULL);
			}
			k = 0;
			while (s[i] != c && s[i] != '\0')
				res[q][k++] = s[i++];
			res [q][k] = '\0';
			q++;
		}
	}
	res[q] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		q;

	i = 0;
	q = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_words_count(s, c) + 1));
	if (res == NULL)
		return (NULL);
	res = ft_wordprint(res, s, c, q);
	return (res);
}
