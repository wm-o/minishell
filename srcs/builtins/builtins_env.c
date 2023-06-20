/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:38:32 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/17 18:24:11 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static void	print_env(t_value *env)
{
	ft_putstr_fd(env->key, 1);
	ft_putchar_fd('=', 1);
	ft_putendl_fd(env->value, 1);
}

int	ft_env(t_process *p, t_shell *s)
{
	t_value	*temp;
	int		arg_cnt;
	int		i;

	arg_cnt = ft_arg_len(p);
	if (arg_cnt > 1)
		return (builtins_error(p, 1, TOO_MANY_ARGS, 1));
	i = 0;
	while (i < BUCKET_SIZE)
	{
		if (s->b[i].head)
		{
			temp = s->b[i].head;
			while (temp)
			{
				if (temp->value)
					print_env(temp);
				temp = temp->next;
			}
		}
		i++;
	}
	return (0);
}
