/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:34 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:19:35 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

t_state	lexer_general(t_toks *t)
{
	char	c;

	c = cur_tok(t);
	if (ft_isblank(c))
		return (STATE_BLANK);
	else if (ft_isnull(c))
		return (STATE_EOF);
	else if (ft_isquote(c))
		return (STATE_QUOTE);
	else if (ft_isredir(c))
		return (STATE_REDIR);
	else if (divide_case(c))
		return (STATE_DIVIDE);
	else
		return (STATE_STR);
	return (STATE_END);
}
