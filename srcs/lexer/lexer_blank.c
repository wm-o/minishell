/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_blank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:21 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:19:22 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

t_state	lexer_blank(t_toks *t)
{
	if (next_tok(t) == 0)
		return (STATE_GENERAL);
	while (ft_isblank(cur_tok(t)))
		t->pos++;
	return (STATE_GENERAL);
}
