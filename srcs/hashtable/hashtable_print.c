/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:17:53 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:19:06 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hash.h"
#include <stdio.h>

void	hashtable_print(t_hashtable *b)
{
	int		i;
	t_value	*temp;

	i = 0;
	while (i < BUCKET_SIZE)
	{
		if (b[i].head)
		{
			temp = b[i].head;
			while (temp)
			{
				printf("%s=%s\n", temp->key, temp->value);
				temp = temp->next;
			}
		}
		i++;
	}
}
