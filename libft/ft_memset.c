/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:24:10 by seojulee          #+#    #+#             */
/*   Updated: 2022/11/27 19:08:42 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;
	unsigned char	t;
	size_t			i;

	dst = (unsigned char *)b;
	t = c;
	i = 0;
	while (i < len)
	{
		dst[i] = t;
		i++;
	}
	return (dst);
}
