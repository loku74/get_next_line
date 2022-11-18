/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:08:48 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/18 14:45:36 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*format(char *str)
{
	if (!str)
		return (NULL);

}

char *get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	static int	b_read = BUFFER_SIZE;

	line = NULL;
	if (buf[0])
		line = add_buf(line, buf);
	if (buf[0])
		line = add_buf(line, buf);
	if (fd < 0 || fd > 1023) 
		return (NULL);
	while (b_read > 0 && !ft_strchr(buf, '\n'))
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read <= 0)
			break ;
		line = add_buf(line, buf);
	}
	line = format(line);
	return (line);
}
