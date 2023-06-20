/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:16:09 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:16:11 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expand.h"

char	*expand_str(char *str, char *temp, t_toks *tokens)
{
	int		i;
	char	*f;

	i = 0;
	f = temp;
	while (str[i])
	{
		if (str[i] == '\\' || str[i] == ';')
			temp = parse_backslash(str, temp, &i, tokens);
		else if (str[i] == '$')
			temp = parse_dollar(str, temp, &i, tokens->b);
		else if (str[i] == '\'' || str[i] == '"')
			temp = parse_quote(str, temp, &i, tokens);
		else
		{
			temp = char_append(temp, str[i]);
			i++;
		}
	}
	free(str);
	return (temp);
}

void	expand(t_token_list *t, t_toks *tokens)
{
	char	*temp;

	if (t == 0)
		return ;
	expand(t->next, tokens);
	if (t->data.type != TOK_STR)
		return ;
	temp = ft_strdup("");
	if (!temp)
		exit(1);
	t->data.buf = expand_str(t->data.buf, temp, tokens);
}
