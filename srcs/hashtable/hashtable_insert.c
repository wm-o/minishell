/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:17:41 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 18:41:22 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hash.h"
#include "../../includes/minishell.h"

static t_value	*new_value(char *key, char *value)
{
	t_value	*new;

	new = (t_value *)xmalloc(sizeof(t_value));
	new->key = key;
	new->value = value;
	new->prev = 0;
	new->next = 0;
	return (new);
}

static void	delete_same_index(t_hashtable *b, char *key)
{
	t_value	*temp;
	int		index;

	index = hash_function(key);
	temp = b[index].head;
	while (temp)
	{
		if (!ft_strcmp(temp->key, key))
		{
			hashtable_delete(b, key);
			return ;
		}
		temp = temp->next;
	}
}

void	hashtable_insert(t_hashtable *b, char *key, char *value)
{
	t_value	*new;
	int		index;

	new = new_value(key, value);
	index = hash_function(key);
	if (b[index].size > 0)
		delete_same_index(b, key);
	if (!b[index].size)
	{
		b[index].size++;
		b[index].head = new;
		b[index].tail = new;
		return ;
	}
	b[index].size++;
	new->prev = b[index].tail;
	b[index].tail->next = new;
	b[index].tail = new;
}
