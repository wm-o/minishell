/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:17:28 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:17:31 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hash.h"

static void	case_head(t_hashtable *b, t_value *target, int index)
{
	if (b[index].size == 0)
	{
		destroy_value(target);
		b[index].head = 0;
		b[index].tail = 0;
		return ;
	}
	b[index].head = b[index].head->next;
	destroy_value(target);
}

static void	case_tail(t_hashtable *b, t_value *target, int index)
{
	b[index].tail = b[index].tail->prev;
	destroy_value(target);
}

void	hashtable_delete(t_hashtable *b, char *key)
{
	t_value	*target;
	int		index;

	target = find_value(b, key);
	if (!target)
		return ;
	index = hash_function(key);
	b[index].size--;
	if (target == b[index].head)
	{
		case_head(b, target, index);
		return ;
	}
	else if (target == b[index].tail)
	{
		case_tail(b, target, index);
		return ;
	}
	target->next->prev = target->prev;
	target->prev->next = target->next;
	destroy_value(target);
}
