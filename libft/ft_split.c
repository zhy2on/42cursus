/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:31:17 by jihoh             #+#    #+#             */
/*   Updated: 2021/05/21 16:39:51 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_strs(char **strs, size_t size)
{
	size_t i;

	i = -1;
	while (++i < size)
		free(strs[i]);
	free(strs);
	return (NULL);
}

size_t		str_size(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && (*s != c))
	{
		s++;
		i++;
	}
	return (i);
}

size_t		strs_size(const char *s, char c)
{
	size_t	i;
	size_t	size;

	size = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (!*s)
			break ;
		i = str_size(s, c);
		s += i + 1;
		if (i)
			size++;
	}
	return (size);
}

const char	*my_strcpy(char *dst, const char *src, char c)
{
	while ((*src != c) && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (src);
}

char		**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;

	if (!s)
		return (NULL);
	strs = (char**)malloc((strs_size(s, c)) * sizeof(char*));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		strs[i] = (char*)malloc((str_size(s, c) + 1) * sizeof(char));
		if (!strs[i])
		{
			free_strs(strs, i);
			return (NULL);
		}
		s = my_strcpy(strs[i++], s, c);
	}
	strs[i] = 0;
	return (strs);
}
