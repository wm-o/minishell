/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_simple_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:22:00 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 23:05:05 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static int	cmd_count(t_token_list *t)
{
	int	i;

	i = 0;
	while (1)
	{
		if (t->data.type != TOK_STR)
			break ;
		if (t->data.buf[0] == '\0')
		{
			t = t->next;
			continue ;
		}
		t = t->next;
		i++;
	}
	return (i);
}

static char	**cmd_join(t_toks *t)
{
	char	**str;
	int		i;
	int		len;

	i = 0;
	len = cmd_count(t->cur);
	str = (char **)xmalloc(sizeof(char *) * (len + 1));
	while (1)
	{
		if (t->cur->data.type != TOK_STR)
			break ;
		if (t->cur->data.buf[0] == '\0')
		{
			t->cur = t->cur->next;
			continue ;
		}
		str[i] = ft_strdup(t->cur->data.buf);
		if (!str[i])
			exit(1);
		t->cur = t->cur->next;
		i++;
	}
	str[i] = 0;
	return (str);
}

t_tree	*simple_command(t_toks *t)
{
	t_tree	*node;

	if (t->cur->data.type & TOK_END)
		return (0);
	if (t->cur->data.type != TOK_STR)
		return (0);
	node = new_node(0, 0);
	node->cmd = cmd_join(t);
	node->type = NODE_CMD;
	return (node);
}
