/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:44:55 by seojulee          #+#    #+#             */
/*   Updated: 2022/11/14 11:30:07 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	t;
	size_t			len;
	size_t			i;

	t = c;
	len = ft_strlen((char *)s);
	i = 0;
	while (*s)
		s++;
	while (i < len + 1)
	{
		if (*s == t)
			return ((char *)s);
		s--;
		i++;
	}
	return (0);
}
