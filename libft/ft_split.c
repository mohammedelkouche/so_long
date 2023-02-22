/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:18:37 by mel-kouc          #+#    #+#             */
/*   Updated: 2022/11/09 21:28:00 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	lenword(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char	**add(char const *s, int c_words, char c, char **alloc)
{
	int		i;
	int		j;
	int		lenw;

	i = 0;
	while (i < c_words)
	{
		while (*s == c)
			s++;
		lenw = lenword(s, c);
		alloc[i] = (char *)malloc(sizeof(char) * lenw + 1);
		if (!alloc[i])
			return (ft_free(alloc));
		j = 0;
		while (j < lenw)
		{
			alloc [i][j] = *s++;
			j++;
		}
		alloc [i][j] = '\0';
		i++;
	}
	alloc[i] = 0;
	return (alloc);
}

char	**ft_split(char const *s, char c)
{
	int		c_words;
	char	**alloc;

	if (!s)
		return (0);
	c_words = countwords(s, c);
	alloc = (char **)malloc(sizeof(char *) * (c_words + 1));
	if (!alloc)
		return (NULL);
	alloc = add(s, c_words, c, alloc);
	return (alloc);
}
