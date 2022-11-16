#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		res_i;
	int		res_size;

	res_size = ft_strlen(s1) + ft_strlen(s2) + 1; 
	res = (char *)malloc(sizeof(char) * res_size);
	if (!res)
		return (NULL);
	i = 0;
	res_i = 0;
	while (s1[i])
		res[res_i++] = s1[i++];
	i = 0;
	while (s2[i])
		res[res_i++] = s2[i++];
	res[res_i] = '\0';
	return (res);
}

int	is_char_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	f(char *str, char c)
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

char	*format(char *str)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * (f(str, '\n') + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	printf("LA\n");
	res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*format_str(char **str)
{
	char	*res;
	int		i;
	int		res_i;

	i = 0;
	while (*str[i] != '\n')
		i++;
	i++;
	res = (char *)malloc(sizeof(char *) * ft_strlen(*(&str[i] + 1)));
	if (!res)
		return (NULL);
	res_i = 0;	
	while (*str[i])
		res[res_i++] = *str[i++];
	res[res_i] = '\0';
	free(*str);
	return (res);
	return (NULL);
}
