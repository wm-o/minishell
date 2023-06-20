/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:38:19 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/18 14:59:33 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	ft_unset(t_process *p, t_shell *s)
{
	int	r_value;
	int	arg_cnt;
	int	i;

	r_value = 0;
	arg_cnt = ft_arg_len(p);
	if (arg_cnt == 1)
		return (r_value);
	i = 1;
	while (p->argv[i])
	{
		if (!p->argv[i])
			break ;
		if (!key_valid(p->argv[i]))
			r_value += builtins_error(p, i, NOT_VALID_ID, 1);
		hashtable_delete(s->b, p->argv[i]);
		i++;
	}
	if (r_value)
		r_value = 1;
	return (r_value);
}
