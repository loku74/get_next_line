/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:08:48 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/17 16:43:50 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	char	*ret;
	int		i;

	ret = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	res_length;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	res_length = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * res_length);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	res[res_length - 1] = '\0';
	return (res);
}

char *get_next_line(int fd)
{
	static char	*str = NULL;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			b_read;
	char		**tab;

	b_read = (int)BUFFER_SIZE;
	if (fd < 0 || b_read <= 0)
		return (NULL);
	while (b_read > 0 && !is_in_str(str, '\n'))
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read <= -1)
			return (NULL);
		buf[b_read] = '\0';
		temp = ft_strdup(str);
		free(str);
		str = ft_strjoin(temp, buf);
		free(temp);
	}
	tab = ft_split(str, '\n');
	temp = tab[0];
	free(str);
	if (tab[1])
		str = tab[1];
	free(tab);
	return (temp);
}
