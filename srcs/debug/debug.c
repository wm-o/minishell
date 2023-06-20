/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:08:06 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 10:26:16 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/debug.h"
#include "../../includes/execute.h"

void	cmd_error(char *cmd, char *msg, int status, t_shell *s)
{
	ft_putstr_fd(SHELL_NAME, 2);
	ft_putstr_fd(": ", 2);
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(msg, 2);
	exit(status);
	(void)s;
}

void	command_error(char *cmd, t_shell *s)
{
	ft_putstr_fd(SHELL_NAME, 2);
	ft_putstr_fd(": ", 2);
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(CMD_NOT_FOUND, 2);
	exit(127);
	(void)s;
}

void	print_file_error(char *file, char *msg)
{
	ft_putstr_fd(SHELL_NAME, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
}

void	check_open_error(t_process *p, t_shell *s)
{
	struct stat	st;

	stat(p->file, &st);
	if ((p->flag & FLAG_OPEN_ERR))
	{
		if (!(S_IFREG & st.st_mode))
			print_file_error(p->file, NO_SUCH);
		else if (!(S_IRUSR & st.st_mode) || !(S_IWUSR & st.st_mode))
			print_file_error(p->file, PERMISSION_DENIED);
		exit(1);
	}
	(void)s;
}

int	check_open_error_builtin(t_process *p, t_shell *s)
{
	extern int	g_status;
	struct stat	st;

	stat(p->file, &st);
	if ((p->flag & FLAG_OPEN_ERR))
	{
		if (!(S_IFREG & st.st_mode))
			print_file_error(p->file, NO_SUCH);
		else if (!(S_IRUSR & st.st_mode) || !(S_IWUSR & st.st_mode))
			print_file_error(p->file, PERMISSION_DENIED);
		g_status = 1;
		return (1);
	}
	(void)s;
	return (0);
}
