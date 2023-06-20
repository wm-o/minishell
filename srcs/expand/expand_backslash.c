/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_backslash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:16:22 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:16:24 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expand.h"

char	*parse_backslash(char *str, char *temp, int *i, t_toks *tokens)
{
	if (str[*i] == ';')
		tokens->syntax_error = 1;
	(*i)++;
	if (str[*i] == '\'' || str[*i] == '"' || str[*i] == '\\')
	{
		temp = char_append(temp, str[*i]);
		(*i)++;
	}
	else if (str[*i] == '\0')
		tokens->syntax_error = 1;
	return (temp);
}
