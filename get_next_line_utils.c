#include "get_next_line.h"

char	*ft_strdup(char *str, int n, int *size)
{
	char	*ret;
	int		i;

	*size += n;
	printf("size: %d | next_line: %d\n", *size, n);
	ret = (char *)malloc((n + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ret[i] = str[i];
		printf("%s | %s\n", ret, str);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	next_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}
