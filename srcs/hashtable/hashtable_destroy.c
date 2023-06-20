/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:17:33 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:17:34 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hash.h"

void	destroy_value(t_value *v)
{
	free(v->key);
	free(v->value);
	v->key = 0;
	v->value = 0;
	free(v);
	v = 0;
}

void	destroy_values(t_value *v)
{
	if (!v)
		return ;
	destroy_values(v->next);
	destroy_value(v);
}

void	destroy_hashtable(t_hashtable *b)
{
	int	i;

	i = 0;
	while (i < BUCKET_SIZE)
	{
		if (b[i].size > 0)
			destroy_values(b[i].head);
		i++;
	}
	free(b);
}
