/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:25:01 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:25:03 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"
#include "../../includes/minishell.h"

t_tree	*new_node(t_tree *left, t_tree *right)
{
	t_tree	*new;

	new = (t_tree *)xmalloc(sizeof(t_tree));
	new->left = left;
	new->right = right;
	return (new);
}
