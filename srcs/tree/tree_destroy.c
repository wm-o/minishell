/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:24:58 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:24:59 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"

void	tree_destroy(t_tree *t)
{
	int	i;

	if (!t)
		return ;
	tree_destroy(t->left);
	tree_destroy(t->right);
	if (t->type & NODE_CMD)
	{
		i = 0;
		while (t->cmd[i])
		{
			free(t->cmd[i]);
			i++;
		}
		free(t->cmd);
	}
	if (t->type & NODE_REDIR)
		free(t->file);
	free(t);
}
