/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:54:10 by jihoh             #+#    #+#             */
/*   Updated: 2021/05/17 19:16:21 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	sign;
	int	num;
	int cut;

	sign = 1;
	num = 0;
	cut = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (cut > 20)
		{
			if (sign < 0)
				return (0);
			else
				return (-1);
		}
		num *= 10;
		num += *str++ - '0';
		cut++;
	}
	return (sign * num);
}
