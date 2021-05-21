/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:35:33 by jihoh             #+#    #+#             */
/*   Updated: 2021/05/21 17:37:57 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_freeall(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

size_t			ft_wordcnt(const char *s, char c)
{
	size_t			cnt;
	size_t			i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

char			*ft_worddup(const char *s, char c)
{
	size_t			len;
	char			*ptr;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	if (!(ptr = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

char			**ft_split(const char *s, char c)
{
	char			**ptr;
	size_t			len;
	size_t			i;
	size_t			j;

	if (!s)
		return (NULL);
	len = ft_wordcnt(s, c);
	if (!(ptr = (char **)ft_calloc(len + 1, sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < len && s[j])
	{
		if (s[j] != c)
		{
			if (!(ptr[i++] = ft_worddup(&(s[j]), c)))
				return (ft_freeall(ptr));
			while (s[j] && s[j] != c)
				j++;
		}
		else
			j++;
	}
	return (ptr);
}
