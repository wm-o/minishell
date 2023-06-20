/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:57:18 by seojulee          #+#    #+#             */
/*   Updated: 2022/11/27 18:36:01 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	if (!dst && !src)
		return (0);
	str1 = dst;
	str2 = (unsigned char *)src;
	i = 0;
	if (str1 > str2)
	{
		while (i < len)
		{
			str1[(len - 1) - i] = str2[(len - 1) - i];
			i++;
		}
		return (dst);
	}
	while (i < len)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dst);
}
