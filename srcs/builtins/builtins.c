/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:16:04 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/18 15:00:13 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"
#include "../../includes/execute.h"

int	is_builtin(t_process *p, t_shell *s)
{
	if (!p->argv[0])
		return (0);
	if (!ft_strcmp("cd", p->argv[0]))
		return (1);
	else if (!ft_strcmp("echo", p->argv[0]))
		return (1);
	else if (!ft_strcmp("env", p->argv[0]))
		return (1);
	else if (!ft_strcmp("exit", p->argv[0]))
		return (1);
	else if (!ft_strcmp("export", p->argv[0]))
		return (1);
	else if (!ft_strcmp("pwd", p->argv[0]))
		return (1);
	else if (!ft_strcmp("unset", p->argv[0]))
		return (1);
	(void)s;
	return (0);
}

int	builtins_check(t_process *p, t_shell *s)
{
	if (!p->argv[0])
		return (0);
	if (!ft_strcmp("cd", p->argv[0]))
		return (ft_cd(p, s));
	else if (!ft_strcmp("echo", p->argv[0]))
		return (ft_echo(p));
	else if (!ft_strcmp("env", p->argv[0]))
		return (ft_env(p, s));
	else if (!ft_strcmp("exit", p->argv[0]))
		return (ft_exit(p));
	else if (!ft_strcmp("export", p->argv[0]))
		return (ft_export(p, s));
	else if (!ft_strcmp("pwd", p->argv[0]))
		return (ft_pwd());
	else if (!ft_strcmp("unset", p->argv[0]))
		return (ft_unset(p, s));
	return (-1);
}

int	builtins_error(t_process *p, int index, char *msg, int err_code)
{
	extern int	g_status;

	ft_putstr_fd(SHELL_NAME, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(p->argv[0], 2);
	ft_putstr_fd(": ", 2);
	if (p->argv[index])
	{
		ft_putstr_fd(p->argv[index], 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(msg, 2);
	g_status = err_code;
	return (err_code);
}
