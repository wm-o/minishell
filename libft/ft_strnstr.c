/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:44:59 by seojulee          #+#    #+#             */
/*   Updated: 2022/11/14 11:30:04 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (*haystack != '\0' && i < len)
	{
		if (*haystack == needle[0])
		{
			j = 0;
			while (j <= (size_t)ft_strlen((char *)needle) && (i + j) <= len)
			{
				if (needle[j] == '\0')
					return ((char *)haystack);
				if (*(haystack + j) != needle[j])
					break ;
				j++;
			}
		}
		haystack++;
		i++;
	}
	return (0);
}
