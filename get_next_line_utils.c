/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:08:49 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/17 16:42:51 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static void	*free_all(char **tab, size_t nelem)
{
	size_t	i;

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

static unsigned int	count_words(char *str, char c)
{
	size_t			i;
	unsigned int	count;

	count = 1;
	i = 0;
	while (str[i] == c)
		i++;
	if (i == (size_t)ft_strlen(str))
		return (count);
	while (i < (size_t)ft_strlen(str))
	{
		if (str[i] != c)
		{
			count++;
			while (i < (size_t)ft_strlen(str))
			{
				if (str[i] == c)
					break ;
				i++;
			}
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
	while (i < (size_t)ft_strlen(s))
	{
		if (next_c(&s[i], c))
		{
			tab[j] = (char *)malloc(sizeof(char) * (next_c(&s[i], c) + 1));
			if (!tab[j])
				return (free_all(tab, j));
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
