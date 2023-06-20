/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:24:37 by wmo               #+#    #+#             */
/*   Updated: 2023/05/19 12:39:19 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/hash.h"

int	check_shlvl(t_value *value)
{
	int		num;

	if (!value || !value->value)
		return (1);
	num = ft_atoi(value->value);
	if (num <= 0)
		return (1);
	return (num + 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 == 0 && *s2 == 0)
		return (0);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	*xmalloc(size_t size)
{
	void	*p;

	if (size == 0)
		size = 1;
	p = malloc(size);
	if (!p)
		exit(1);
	return (p);
}

void	destroy_pid(t_pid_list *p)
{
	if (!p)
		return ;
	destroy_pid(p->next);
	free(p);
}
