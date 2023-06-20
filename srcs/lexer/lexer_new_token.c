/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_new_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:37 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:19:38 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

void	new_token(t_toks *t, t_token_type type)
{
	t_token			token;
	t_token_list	*temp;

	if (type & TOK_END)
		token.buf = NULL;
	else
		token.buf = ft_substr(t->str, t->start, t->pos - t->start);
	token.type = type;
	delete_space(&token);
	temp = new_list(token);
	push_back(t, temp);
	t->start = t->pos;
}
