/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:55:14 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/18 18:12:46 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	ft_arg_len(t_process *p)
{
	int	i;

	i = 1;
	while (p->argv[i])
		i++;
	return (i);
}

int	ft_key_len(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

int	key_valid(char *key)
{
	int	i;

	i = 0;
	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (0);
	while (ft_isalnum(key[i]) || key[i] == '_')
		i++;
	if (key[i] == 0)
		return (1);
	return (0);
}

void	bubble_sort(char **str, int size)
{
	char	*tmp;
	int		s1_len;
	int		i;

	while (size)
	{
		i = 0;
		while (i < (size - 1))
		{
			tmp = 0;
			s1_len = ft_strlen(str[i]);
			if (ft_strncmp(str[i], str[i + 1], s1_len) > 0)
			{
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
			}
			i++;
		}
		size--;
	}
}
