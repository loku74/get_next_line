#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char 			*get_next_line(int fd);

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, char c);

void	ft_treat_right_side(char **str);
char	*ft_treat_left_side(char *str);

#endif
