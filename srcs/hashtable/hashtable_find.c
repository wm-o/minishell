/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:17:35 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 18:35:34 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hash.h"
#include "../../includes/minishell.h"

t_value	*find_value(t_hashtable *b, char *key)
{
	int		index;
	t_value	*temp;

	index = hash_function(key);
	if (b[index].size <= 0)
		return (0);
	temp = b[index].head;
	while (temp)
	{
		if (!ft_strcmp(temp->key, key))
			return (temp);
		temp = temp->next;
	}
	return (0);
}
