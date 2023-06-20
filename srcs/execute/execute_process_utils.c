/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_process_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:12:21 by wmo               #+#    #+#             */
/*   Updated: 2023/05/19 14:36:24 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"
#include "../../includes/minishell.h"

void	new_pid(t_shell *s)
{
	t_pid_list	*p;

	p = (t_pid_list *)xmalloc(sizeof(t_pid_list));
	ft_memset(p, 0, sizeof(t_pid_list));
	if (s->pid_q.head == 0)
	{
		s->pid_q.head = p;
		s->pid_q.tail = p;
		return ;
	}
	s->pid_q.tail->next = p;
	s->pid_q.tail = p;
}

void	wait_child_process(t_shell *s)
{
	int			status;
	t_pid_list	*temp;
	extern int	g_status;

	signal_init(3);
	temp = s->pid_q.head;
	while (temp)
	{
		while (waitpid(temp->pid, &status, 0) >= 0)
			;
		temp = temp->next;
	}
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		g_status = (WTERMSIG(status) + 128);
	}
	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status);
}

void	close_other_pipes(t_process *p)
{
	int	i;

	i = 0;
	while (i < p->cur)
	{
		if (p->fd[i][0] != p->pipe_in_fd)
			xclose(p->fd[i][0]);
		if (p->fd[i][1] != p->pipe_out_fd)
			xclose(p->fd[i][1]);
		i++;
	}
}

void	dup_process_fd(t_process *p)
{
	if (p->infile_fd != 0)
		xdup2(p->infile_fd, 0);
	else if (p->pipe_in_fd != 0)
		xdup2(p->pipe_in_fd, 0);
	if (p->outfile_fd != 1)
		xdup2(p->outfile_fd, 1);
	else if (p->pipe_out_fd != 0)
		xdup2(p->pipe_out_fd, 1);
}

int	xdup(int fd)
{
	int	new;

	new = dup(fd);
	if (new < 0)
		exit(1);
	return (new);
}
