/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:16:26 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:16:56 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expand.h"

static char	*parse_s_quote(char *str, char *temp, int *i, t_toks *tokens)
{
	while (str[*i])
	{
		if (str[*i] == '\'')
		{
			(*i)++;
			return (temp);
		}
		else
			temp = char_append(temp, str[*i]);
		(*i)++;
	}
	tokens->syntax_error = 1;
	return (temp);
}

static char	*parse_d_quote(char *str, char *temp, int *i, t_toks *tokens)
{
	while (str[*i])
	{
		if (str[*i] == '\"')
		{
			(*i)++;
			return (temp);
		}
		else if (str[*i] == '$')
		{
			temp = parse_dollar(str, temp, i, tokens->b);
		}
		else
		{
			temp = char_append(temp, str[*i]);
			(*i)++;
		}
	}
	tokens->syntax_error = 1;
	return (temp);
}

char	*parse_quote(char *str, char *temp, int *i, t_toks *tokens)
{
	if (str[*i] == '\'')
	{
		(*i)++;
		temp = parse_s_quote(str, temp, i, tokens);
	}
	else if (str[*i] == '"')
	{
		(*i)++;
		temp = parse_d_quote(str, temp, i, tokens);
	}
	return (temp);
}
