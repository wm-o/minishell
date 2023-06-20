/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:19 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:20:18 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer.h"

static void	lexer_init(t_toks *t, char *str, t_shell *s)
{
	ft_memset(t, 0, sizeof(t_toks));
	t->state = STATE_GENERAL;
	t->str = str;
	t->len = ft_strlen(str);
	t->b = s->b;
}

static int	lexer_err(t_toks *t)
{
	new_token(t, TOK_STR);
	return (STATE_EOF);
}

void	lexer(t_toks *t, char *str, t_shell *s)
{
	lexer_init(t, str, s);
	while (t->state != STATE_END)
	{
		if (t->state == STATE_GENERAL)
			t->state = lexer_general(t);
		else if (t->state == STATE_BLANK)
			t->state = lexer_blank(t);
		else if (t->state == STATE_QUOTE)
			t->state = lexer_quote(t);
		else if (t->state == STATE_EOF)
			t->state = lexer_eof(t);
		else if (t->state == STATE_STR)
			t->state = lexer_str(t);
		else if (t->state == STATE_REDIR)
			t->state = lexer_redirect(t);
		else if (t->state == STATE_DIVIDE)
			t->state = lexer_divide(t);
		else if (t->state == STATE_ERR)
			t->state = lexer_err(t);
	}
}
