#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	char	*line;
	int		fd;

	fd = open("go.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	return (0);
}
