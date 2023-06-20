/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:04:28 by seojulee          #+#    #+#             */
/*   Updated: 2022/11/21 11:11:44 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nbr(long long n, int fd)
{
	char		arr[10];
	long long	minus;
	long long	i;

	minus = 0;
	if (n < 0)
	{
		n *= -1;
		minus = 1;
	}
	i = 9;
	while (n)
	{
		arr[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (minus)
		write(fd, "-", 1);
	while (i < 9)
		write(fd, &arr[++i], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (!n)
		write(fd, "0", 1);
	else
		ft_nbr(n, fd);
}
