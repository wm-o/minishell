/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:38:34 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/18 15:00:25 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static int	is_opt(char *str)
{
	int	i;

	i = 2;
	if (ft_strncmp("-n", str, 2))
		return (0);
	if (!ft_strcmp("-n", str))
		return (1);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static int	print_arg(char **argv, int i, int line_flag)
{
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		if (!argv[i + 1])
			break ;
		ft_putstr_fd(" ", 1);
		i++;
	}
	if (line_flag)
		ft_putstr_fd("\n", 1);
	return (0);
}

int	ft_echo(t_process *p)
{
	int	i;
	int	line_flag;
	int	arg_cnt;

	i = 0;
	line_flag = 1;
	arg_cnt = ft_arg_len(p);
	if (arg_cnt == 1)
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	while (p->argv[++i])
	{
		if (!is_opt(p->argv[i]))
			break ;
		line_flag = 0;
	}
	return (print_arg(p->argv, i, line_flag));
}
