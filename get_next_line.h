#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

char 			*get_next_line(int fd);

int		next_line(char *buf);
char	*ft_strdup(char *str, int n, int *size);

#endif
