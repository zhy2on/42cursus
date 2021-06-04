/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:43:52 by jihoh             #+#    #+#             */
/*   Updated: 2021/05/26 16:08:28 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		*update_line(static char **backup, char *pcut, char **line)
{
	char	*tmp;

	*pcut = '\0';
	*line = ft_strdup(*backup);
	free(*backup);
	if (!tmp = ft_strdup(pcut + 1))
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
	char		*pcut;
	int			rsize;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!(pcut = ft_strchr(buf, '\n'))
				&& (rsize = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rsize] = '\0';
		if (!backup[fd])
			backup[fd] = ft_strdup("\0");
		tmp = ft_strjoin(backup[fd], buf);
		bfree(backup[fd]);
		backup[fd] = tmp;
	}
	//if (rsize < 0)
	// return (-1);
	return (update_line(backup[fd], pcut, line));
}
