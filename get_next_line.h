#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H

# include <stdlib.h>
# include <unistd.h>

char 	*get_next_line(int fd);
char	**ft_split(char *str, char c);

#endif
