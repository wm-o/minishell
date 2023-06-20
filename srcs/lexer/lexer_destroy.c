/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:26 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:19:27 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

void	lexer_destroy(t_token_list *t)
{
	if (!t)
		return ;
	lexer_destroy(t->next);
	free(t->data.buf);
	free(t);
}
