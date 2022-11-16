#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*str = "";
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			b_read;

	b_read = (int)BUFFER_SIZE;
	if (fd < 0 || b_read <= 0)
		return (NULL);
	while (b_read > 0)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read == -1)
			return (NULL);
		buf[b_read] = '\0';
		temp = str;
		str = ft_strjoin(temp, buf);
		if (is_char_in_str(str, '\n') > 0)
			break;
	}
	temp = format(str);
	str = format_str(&str);
	return (temp);
}
