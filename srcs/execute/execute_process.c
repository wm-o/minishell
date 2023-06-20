/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:11:25 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 22:46:03 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"
#include "../../includes/builtins.h"
#include "../../includes/debug.h"
#include "../../includes/hash.h"

static void	execute_child(t_tree *t, t_process *p, t_shell *s)
{
	extern int	g_status;

	signal_init(1);
	check_open_error(p, s);
	close_other_pipes(p);
	dup_process_fd(p);
	if (builtins_check(p, s) >= 0)
		exit(g_status);
	exec_cmd(t, p, s);
}

void	execute_builtin(t_tree *t, t_process *p, t_shell *s)
{
	extern int	g_status;

	if (check_open_error_builtin(p, s))
		return ;
	p->in = xdup(0);
	p->out = xdup(1);
	dup_process_fd(p);
	g_status = builtins_check(p, s);
	xdup2(p->in, 0);
	xdup2(p->out, 1);
	xclose(p->in);
	xclose(p->out);
	(void)t;
}

void	execute_process(t_tree *t, t_process *p, t_shell *s)
{
	if (is_builtin(p, s) && p->pipe_len == 0)
	{
		execute_builtin(t, p, s);
		return ;
	}
	s->new_term.c_lflag |= (ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &(s->new_term));
	new_pid(s);
	s->pid_q.tail->pid = fork();
	if (s->pid_q.tail->pid == -1)
		exit(1);
	if (s->pid_q.tail->pid == 0)
		execute_child(t, p, s);
	if (p->infile_fd != 0)
		xclose(p->infile_fd);
	if (p->outfile_fd != 1)
		xclose(p->outfile_fd);
}
