/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:26:08 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/11 14:56:06 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*free_all(char **tab, unsigned int nelem)
{
	unsigned int	i;

	i = 0;
	while (i < nelem)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static size_t	next_c(char *str, char c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

unsigned int	count_words(char *str, char c)
{
	size_t			i;
	size_t			len_str;
	unsigned int	count;

	len_str = ft_strlen(str);
	count = 1;
	i = 0;
	while (str[i] == c)
		i++;
	if (i == len_str)
		return (count);
	while (i < len_str)
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c)
				i++;
		}
		i++;
	}
	return (count);
}

static char	**ft_strsplit(char **tab, char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		if (next_c(&s[i], c))
		{
			tab[j] = (char *)malloc(sizeof(char) * (next_c(&s[i], c) + 1));
			if (!tab[j])
				return (free_all(tab, count_words(s, c) + 1));
			k = 0;
			while (next_c(&s[i], c))
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char *str, char c)
{
	char			**tab;

	if (!str)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * ((count_words(str, c))));
	if (!tab)
		return (NULL);
	return (ft_strsplit(tab, str, c));
}
