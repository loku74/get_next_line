#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *str = NULL;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			b_read;
	
	b_read = BUFFER_SIZE;
	if (fd < 0 || b_read <= 0)
		return (NULL);
	while (b_read > 0)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read == -1)
			return (NULL);
		buf[BUFFER_SIZE] = '\0';
		temp = str;
		str = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(str, '\n'))
			break;
	}
	temp = ft_treat_left_side(str);
	ft_treat_right_side(&str);
	return (temp);
}
