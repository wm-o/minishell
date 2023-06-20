/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command_redir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:21:57 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:22:44 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static int	check_node_type(char *s)
{
	if (!ft_strncmp(s, "<<", 2))
		return (NODE_REDIRECT_HEREDOC);
	else if (!ft_strncmp(s, ">>", 2))
		return (NODE_REDIRECT_APPEND);
	else if (!ft_strncmp(s, "<", 1))
		return (NODE_REDIRECT_IN);
	else
		return (NODE_REDIRECT_OUT);
}

static int	is_syntax_error(t_toks *t)
{
	if (t->cur->data.type != TOK_STR)
	{
		t->syntax_error = 1;
		return (1);
	}
	return (0);
}

t_tree	*command_redir(t_toks *t)
{
	t_tree		*node;
	t_tree		*right;
	char		*temp;
	int			type;

	if (t->cur->data.type == TOK_END || t->syntax_error)
		return (0);
	node = simple_command(t);
	if (t->cur->data.type & TOK_RDIR)
	{
		type = check_node_type(t->cur->data.buf);
		t->cur = t->cur->next;
		if (is_syntax_error(t))
			return (node);
		temp = ft_strdup(t->cur->data.buf);
		if (!temp)
			exit(1);
		t->cur = t->cur->next;
		right = command_redir(t);
		node = new_node(node, right);
		node->file = temp;
		node->type = type;
	}
	return (node);
}
