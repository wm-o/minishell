/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:16:36 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 21:15:19 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expand.h"

static char	*parse_exit_status(char *temp, int *i)
{
	extern int	g_status;
	char		*exit_status;

	(*i)++;
	exit_status = ft_itoa(g_status);
	if (!exit_status)
		exit(1);
	temp = str_append(temp, exit_status);
	return (temp);
}

static char	*get_env(char *str, int start, int end, t_hashtable *b)
{
	char	*substr;
	char	*env;
	t_value	*value;

	substr = ft_substr(str, start, end - start);
	if (!substr)
		exit(1);
	value = find_value(b, substr);
	free(substr);
	if (!value || !value->value)
		return (0);
	env = ft_strdup(value->value);
	if (!env)
		exit(1);
	return (env);
}

char	*parse_dollar(char *str, char *temp, int *i, t_hashtable *b)
{
	int		start;
	char	*env;

	(*i)++;
	if (str[*i] == '"' || str[*i] == '\0' || str[*i] == 32)
		return (char_append(temp, '$'));
	if (str[*i] == '?')
		return (parse_exit_status(temp, i));
	start = *i;
	while (ft_isalnum(str[*i]) || str[*i] == '_')
		(*i)++;
	env = get_env(str, start, *i, b);
	if (!env)
		return (temp);
	temp = str_append(temp, env);
	if (!temp)
		exit(1);
	return (temp);
}
