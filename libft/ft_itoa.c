/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:50:28 by jihoh             #+#    #+#             */
/*   Updated: 2021/05/21 18:26:19 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_abs(int n)
{
	return ((n > 0) ? n : -n);
}

int		ft_itoa_len(int n)
{
	size_t	len;

	len = (n <= 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		sign;

	sign = (n < 0) ? -1 : 1;
	len = ft_itoa_len(n);
	if (!(ret = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (--len >= 0)
	{
		ret[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
	}
	if (sign < 0)
		ret[0] = '-';
	return (ret);
}
