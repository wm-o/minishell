/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:21:54 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 14:14:18 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

t_tree	*command_pipe(t_toks *t)
{
	t_tree	*node;
	t_tree	*right;

	if (t->cur->data.type == TOK_END || t->syntax_error)
		return (0);
	node = command_redir(t);
	if (t->cur->data.type == TOK_PIPE)
	{
		t->cur = t->cur->next;
		right = command_pipe(t);
		node = new_node(node, right);
		node->type = NODE_PIPE;
		if (node->left == 0 || node ->right == 0)
		{
			t->syntax_error = 1;
			return (node);
		}
	}
	return (node);
}
