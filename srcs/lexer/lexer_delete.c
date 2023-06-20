/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:23 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:20:30 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

void	delete_space(t_token *t)
{
	char	*temp;

	if (!t || !t->buf)
		return ;
	temp = ft_strtrim(t->buf, " ");
	if (!temp)
		exit(1);
	free(t->buf);
	t->buf = temp;
}

void	delete_s_quote(t_token *t)
{
	char	*temp;

	if (!t || !t->buf)
		return ;
	temp = ft_strtrim(t->buf, "'");
	if (!temp)
		exit(1);
	free(t->buf);
	t->buf = temp;
}

void	delete_d_quote(t_token *t)
{
	char	*temp;

	if (!t || !t->buf)
		return ;
	temp = ft_strtrim(t->buf, "\"");
	if (!temp)
		exit(1);
	free(t->buf);
	t->buf = temp;
}
