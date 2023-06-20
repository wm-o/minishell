/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:52 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:19:52 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

t_state	lexer_str(t_toks *t)
{
	char	c;

	c = cur_tok(t);
	if (divide_case(c))
	{
		new_token(t, TOK_STR);
		return (STATE_GENERAL);
	}
	else if (ft_isquote(c))
		return (STATE_GENERAL);
	t->pos++;
	return (STATE_STR);
}
