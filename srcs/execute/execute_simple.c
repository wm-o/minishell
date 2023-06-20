/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:15:22 by wmo               #+#    #+#             */
/*   Updated: 2023/05/17 15:51:33 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

void	execute_simple_command(t_tree *t, t_process *p)
{
	int		i;

	if (!t)
		return ;
	if (t->type != NODE_CMD)
		return ;
	i = 0;
	while (t->cmd[i])
	{
		p->argv[p->index] = ft_strdup(t->cmd[i]);
		if (!p->argv[p->index])
			exit(1);
		p->index++;
		i++;
	}
}
