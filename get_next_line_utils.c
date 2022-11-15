#include "get_next_line.h"

void	ft_treat_right_side(char **str)
{
	int		i;
	int		temp_i;
	int		size;
	char	*temp;

	i = ft_strchr(*str, '\n') + 1;
	size = ft_strlen(&(*str)[i]) + 1;
	temp = (char *)malloc(sizeof(char) * size);
	if (!temp)
		return ;
	temp_i = 0;
	while (temp_i < size)
		temp[temp_i++] = (*str)[i++];
	temp[size] = '\0';
	i = 0;
	while ((*str)[i])
		(*str)[i++] = '\0';
	i = 0;
	while (i < size)
	{
		(*str)[i] = temp[i];
		i++;
	}
	free(temp);
}

char	*ft_treat_left_side(char *str)
{
	char	*res;
	int		res_size;
	int		i;

	res_size = ft_strchr(str, '\n') + 1;
	res = (char *)malloc(sizeof(char) * res_size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < res_size)
	{
		res[i] = str[i];
		i++;
	}
	res[res_size] = '\0';
	return (res);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	int		res_i;
	char	*res;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	res_i = 0;
	if (s1)
	{
		i = 0;
		while (s1[i])
			res[res_i++] = s1[i++];
	}
	i = 0;
	while (s2[i])
		res[res_i++] = s2[i++];
	res[len] = '\0';
	return (res);
}
