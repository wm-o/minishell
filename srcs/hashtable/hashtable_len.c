/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:20:40 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/16 10:18:33 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hash.h"

int	hashtable_len(t_hashtable *b)
{
	int		len;
	int		i;
	t_value	*temp;

	len = 0;
	i = 0;
	while (i < BUCKET_SIZE)
	{
		if (b[i].head)
		{
			temp = b[i].head;
			while (temp)
			{
				temp = temp->next;
				len++;
			}
		}
		i++;
	}
	return (len);
}
