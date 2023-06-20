/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:49 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:19:50 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

t_state	lexer_d_redir(t_toks *t, char cur)
{
	t_token_type	type;
	char			c;

	c = cur_tok(t);
	t->pos++;
	if (cur == '>' && c == '>')
		type = TOK_RDI_APPEND;
	else if (cur == '<' && c == '<')
		type = TOK_RDI_HEREDOC;
	else
		type = TOK_ALL;
	new_token(t, type);
	return (STATE_GENERAL);
}

t_state	lexer_redirect(t_toks *t)
{
	t_token_type	type;
	char			c;

	c = cur_tok(t);
	t->pos++;
	if (ft_isredir(cur_tok(t)))
		return (lexer_d_redir(t, c));
	if (c == '<')
		type = TOK_RDI_INPUT;
	else if (c == '>')
		type = TOK_RDI_OUTPUT;
	else
		type = TOK_NONE;
	new_token(t, type);
	return (STATE_GENERAL);
}
