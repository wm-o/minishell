/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_divide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:29 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:19:30 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

t_state	lexer_divide(t_toks *t)
{
	char			c;
	t_token_type	type;

	c = cur_tok(t);
	t->pos++;
	if (c == '|')
		type = TOK_PIPE;
	else
		type = TOK_ALL;
	new_token(t, type);
	return (STATE_GENERAL);
}
