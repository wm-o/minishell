/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:16:32 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 23:48:55 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expand.h"
#include "../../includes/minishell.h"

char	*char_append(char *s, char c)
{
	char	*temp;
	char	*str;

	if (!s)
		return (0);
	temp = (char *)xmalloc(2);
	temp[1] = 0;
	temp[0] = c;
	str = ft_strjoin(s, temp);
	if (!str)
		exit(1);
	free(s);
	free(temp);
	return (str);
}

char	*str_append(char *s1, char *s2)
{
	char	*temp;

	if (!s1 || !s2)
		return (0);
	temp = ft_strjoin(s1, s2);
	if (!temp)
		exit(1);
	free(s1);
	free(s2);
	return (temp);
}
