/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:57:59 by seojulee          #+#    #+#             */
/*   Updated: 2023/04/20 16:25:55 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*arr;

	arr = (char *)malloc(count * size);
	if (arr == 0)
		return (0);
	i = 0;
	while (i < (count * size))
		arr[i++] = 0;
	return ((void *)arr);
}
