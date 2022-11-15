#include "get_next_line.h"

char *get_next_line(int fd)
{
	static int		line = -1;
	static char		*buf;
	static char		**tab;
	static ssize_t	ret;

	if (line == -1)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == BUFFER_SIZE)
		{
			buf[BUFFER_SIZE] = '\0';
			tab = ft_split(buf, '\n');
			free(buf);
		}
		else
		{
			free(buf);
			return (NULL);
		}
	}
	line++;
	return (tab[line]);
	return (NULL);
}
