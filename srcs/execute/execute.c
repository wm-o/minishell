/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:08:28 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 22:49:58 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"
#include "../../includes/minishell.h"

static void	destroy_process(t_process *p)
{
	close_pipeline(p);
	destroy_argv(p);
}

static int	count_pipe(t_tree *t)
{
	int	cnt;

	if (!t)
		return (0);
	cnt = 0;
	cnt += count_pipe(t->left);
	cnt += count_pipe(t->right);
	if (t->type & NODE_PIPE)
		cnt++;
	return (cnt);
}

static void	set_process(t_tree *t, t_process *p)
{
	int	i;

	i = 0;
	ft_memset(p, 0, sizeof(t_process));
	p->outfile_fd = 1;
	p->pipe_len = count_pipe(t);
	if (p->pipe_len)
		p->fd = (int **)xmalloc(sizeof(int *) * p->pipe_len);
	while (i < p->pipe_len)
	{
		p->fd[i] = (int *)xmalloc(sizeof(int) * 2);
		i++;
	}
}

void	execute(t_tree *t, t_shell *s)
{
	t_process	p;

	if (!t)
		return ;
	set_process(t, &p);
	execute_pipe(t, &p, s);
	destroy_process(&p);
	wait_child_process(s);
	signal_init(0);
	s->new_term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &(s->new_term));
	destroy_pid(s->pid_q.head);
	ft_memset(&s->pid_q, 0, sizeof(t_queue));
}
