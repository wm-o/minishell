/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:17:25 by wmo               #+#    #+#             */
/*   Updated: 2023/05/19 12:42:33 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hash.h"

int	hash_function(char *key)
{
	t_ll	hash;
	int		i;

	i = 0;
	hash = 0;
	while (key[i])
	{
		hash = (((hash << 5) + hash) + key[i]) % BUCKET_SIZE;
		i++;
	}
	return ((int)hash % BUCKET_SIZE);
}
