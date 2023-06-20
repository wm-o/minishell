/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:42:30 by seojulee          #+#    #+#             */
/*   Updated: 2022/12/03 20:06:48 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	value;
	long long	minus;
	long long	temp;

	value = 0;
	minus = 1;
	while (*str == 32 || (8 < *str && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		temp = value;
		value = (value * 10) + (*str - '0');
		if (temp > value && minus == 1)
			return (-1);
		if (temp > value && minus == -1)
			return (0);
		str++;
	}
	return (value * minus);
}
