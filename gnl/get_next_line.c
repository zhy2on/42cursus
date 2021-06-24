/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:43:52 by jihoh             #+#    #+#             */
/*   Updated: 2021/06/24 17:48:56 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		update_line(char **backup, int cutidx, char **line)
{
	char	*tmp;

	(*backup)[cutidx] = '\0';
	*line = ft_strdup(*backup);
	free(*backup);
	if (!(tmp = ft_strdup(*backup + cutidx + 1)))
	{
		*backup = NULL;
		return (-1);
	}
	else
		*backup = tmp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		*buf;
	char		*tmp;
	int			cutidx;
	int			rsize;

	cutidx = 0
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!(cutidx = ft_strchr(buf, '\n') - buf)
				&& (rsize = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rsize] = '\0';
		if (!backup[fd])
			backup[fd] = ft_strdup("\0");
		tmp = ft_strjoin(backup[fd], buf);
		free(backup[fd]);
		backup[fd] = tmp;
	}
	free(buf);
	return (update_line(&backup[fd], cutidx, line));
}
