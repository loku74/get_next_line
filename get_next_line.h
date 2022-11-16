#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H

# include <stdlib.h>
# include <unistd.h>

// IL FAUT L'ENLEVER VANT DE PUSH SINON BPOUMEAU VA TE NORMED
# include <stdio.h>
// IL FAUT L'ENLEVER VANT DE PUSH SINON BPOUMEAU VA TE NORMED

char	*get_next_line(int fd);

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		is_char_in_str(char *str, char c);
char	*format(char *str);
char	*format_str(char **str);

#endif
