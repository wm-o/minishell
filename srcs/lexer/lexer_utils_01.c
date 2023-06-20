/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:54 by wmo               #+#    #+#             */
/*   Updated: 2023/05/17 14:57:29 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer.h"

int	ft_isquote(int c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

int	ft_isnull(int c)
{
	if (c == 0)
		return (1);
	return (0);
}

int	ft_isredir(int c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

int	ft_ispipe(int c)
{
	if (c == '|')
		return (1);
	return (0);
}

int	ft_isblank(int c)
{
	if (c == 32)
		return (1);
	return (0);
}
