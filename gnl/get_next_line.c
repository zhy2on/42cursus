/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:43:52 by jihoh             #+#    #+#             */
/*   Updated: 2021/05/25 16:37:02 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*stored_buf[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*where_endl;
	int			size;
	int			stored_size;

	stored_size = 0;
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		stored_size += size;
		if (where_endl = ft_strchr(buf, '\n'))
		{
		}
			
	}


}
