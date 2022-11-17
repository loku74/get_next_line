/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:08:46 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/17 16:43:47 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H

# include <stdlib.h>
# include <unistd.h>

// IL FAUT L'ENLEVER VANT DE PUSH SINON BPOUMEAU VA TE NORMED
# include <stdio.h>
// IL FAUT L'ENLEVER VANT DE PUSH SINON BPOUMEAU VA TE NORMED

char	*get_next_line(int fd);

int		is_in_str(char *str, char c);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *str, char c);

#endif
