/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 07:15:46 by seojulee          #+#    #+#             */
/*   Updated: 2022/12/03 21:44:51 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlen(long long n)
{
	size_t	len;
	int		minus;

	len = 0;
	minus = 1;
	if (!n)
		return (1);
	if (n < 0)
		minus = -1;
	n *= minus;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_llongtoa(long long n)
{
	char	*arr;
	size_t	len;
	size_t	minus;

	minus = 0;
	len = intlen(n);
	if (n < 0)
	{
		minus = 1;
		n *= -1;
		len++;
	}
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == 0)
		return (0);
	arr[len] = '\0';
	while (len)
	{
		arr[--len] = (n % 10) + 48;
		n /= 10;
	}
	if (minus)
		arr[len] = '-';
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;

	arr = ft_llongtoa(n);
	return (arr);
}
