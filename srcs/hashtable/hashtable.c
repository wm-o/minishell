/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:17:39 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:17:40 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hash.h"
#include "../../includes/minishell.h"

t_hashtable	*init_hashtable(void)
{
	t_hashtable	*h;

	h = (t_hashtable *)xmalloc(sizeof(t_hashtable) * BUCKET_SIZE);
	ft_memset(h, 0, sizeof(t_hashtable) * BUCKET_SIZE);
	return (h);
}
