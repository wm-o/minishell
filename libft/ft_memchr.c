/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:45:15 by seojulee          #+#    #+#             */
/*   Updated: 2022/11/14 11:29:26 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	t;
	size_t			i;

	str = (unsigned char *)s;
	t = c;
	i = 0;
	while (i < n)
	{
		if (*str == t)
			return ((unsigned char *)str);
		str++;
		i++;
	}
	return (0);
}
