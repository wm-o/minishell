/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:57 by wmo               #+#    #+#             */
/*   Updated: 2023/05/17 14:58:08 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

int	divide_case(int c)
{
	if (ft_ispipe(c) || ft_isredir(c) || ft_isnull(c))
		return (1);
	if (ft_isblank(c))
		return (1);
	return (0);
}

char	cur_tok(t_toks *t)
{
	char	c;

	c = t->str[t->pos];
	return (c);
}

char	next_tok(t_toks *t)
{
	if (t->pos >= t->len)
		return (0);
	return (t->str[t->pos + 1]);
}

void	push_back(t_toks *t, t_token_list *n)
{
	if (t->head == 0)
	{
		t->head = n;
		t->tail = n;
		return ;
	}
	t->tail->next = n;
	t->tail = n;
}

t_token_list	*new_list(t_token t)
{
	t_token_list	*new;

	new = (t_token_list *)xmalloc(sizeof(t_token_list));
	new->next = 0;
	new->data = t;
	return (new);
}
