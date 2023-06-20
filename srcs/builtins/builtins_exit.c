/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:38:30 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/19 14:37:12 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static int	exit_arg_vaild(t_process *p, char *str)
{
	int	value;
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[0] == '-' || str[0] == '+')
			continue ;
		if (!ft_isdigit(str[i]))
			return (builtins_error(p, 1, "numeric argument required", 255));
	}
	value = ft_atoi(str) % 256;
	if (value < 0)
		value += 256;
	return (value);
}

int	ft_exit(t_process *p)
{
	extern int	g_status;
	int			arg_cnt;

	arg_cnt = ft_arg_len(p);
	printf("exit\n");
	if (arg_cnt > 2)
		exit(builtins_error(p, 1, TOO_MANY_ARGS, 1));
	else if (arg_cnt == 2)
		exit(exit_arg_vaild(p, p->argv[1]));
	else
		exit(g_status & 0xFF);
	return (0);
}
