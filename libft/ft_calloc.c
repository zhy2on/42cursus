/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:40:37 by jihoh             #+#    #+#             */
/*   Updated: 2021/05/17 19:45:26 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_calloc(size_t count, size_t size)
{
	void *mem;

	size *= count;
	if ((mem = (void*)malloc(size)))
		ft_bzero(mem, size);
	return (mem);
}
