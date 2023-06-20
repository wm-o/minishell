/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:46 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:20:42 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

static t_state	single_quote(t_toks *t)
{
	char	c;

	while (1)
	{
		c = cur_tok(t);
		if (c == '\0')
			return (STATE_ERR);
		if (c == '\'')
			break ;
		t->pos++;
	}
	t->pos++;
	if (divide_case(cur_tok(t)))
		new_token(t, TOK_STR);
	return (STATE_GENERAL);
}

static t_state	double_quote(t_toks *t)
{
	char	c;

	while (1)
	{
		c = cur_tok(t);
		if (c == '\0')
			return (STATE_ERR);
		if (c == '"')
			break ;
		t->pos++;
	}
	t->pos++;
	if (divide_case(cur_tok(t)))
		new_token(t, TOK_STR);
	return (STATE_GENERAL);
}

t_state	lexer_quote(t_toks *t)
{
	char	c;

	c = cur_tok(t);
	t->pos++;
	if (c == '\'')
		return (single_quote(t));
	else if (c == '"')
		return (double_quote(t));
	return (STATE_GENERAL);
}
