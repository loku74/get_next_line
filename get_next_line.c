#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	static int	b_read;
	static int	b_curr = 0;
	static char	*buf;

	printf("%d | %d\n", b_curr, BUFFER_SIZE);
	if (b_curr == BUFFER_SIZE)
	{
		free(buf);
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	b_read = read(fd, buf, BUFFER_SIZE);
	if (b_read == BUFFER_SIZE)
	{
		buf[BUFFER_SIZE] = '\0';
		return (ft_strdup(&buf[b_curr], next_line(&buf[b_curr]), &b_curr));
	}
	else
	{
		free(buf);
		return (NULL);
	}
}
