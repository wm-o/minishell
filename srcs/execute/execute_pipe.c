/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:10:57 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 17:19:40 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"
#include "../../includes/minishell.h"

static void	init_process(t_process *p)
{
	if (p->cur == 0)
		return ;
	if (p->flag & FLAG_READ_PIPE)
		p->pipe_in_fd = p->fd[p->cur - 1][0];
	p->flag = 0;
}

static void	argv_destroy(t_process *p)
{
	int	i;

	if (p->index > 0)
	{
		i = 0;
		while (p->argv[i])
		{
			free(p->argv[i]);
			i++;
		}
	}
	if (p->argv)
		free(p->argv);
	p->argv = 0;
	p->index = 0;
	p->infile_fd = 0;
	p->outfile_fd = 1;
}

void	set_pipe(t_tree *t, t_process *p, t_shell *s)
{
	xpipe(p->fd[p->cur]);
	p->pipe_out_fd = p->fd[p->cur][1];
	p->cur++;
	(void)s;
	(void)t;
}

void	execute_pipe(t_tree *t, t_process *p, t_shell *s)
{
	argv_destroy(p);
	init_process(p);
	if (t->type & NODE_PIPE)
	{
		set_pipe(t, p, s);
		p->flag |= FLAG_WRITE_PIPE;
		execute_redir(t->left, p, s);
		argv_destroy(p);
		p->flag = FLAG_READ_PIPE;
		p->pipe_out_fd = 1;
		execute_pipe(t->right, p, s);
		return ;
	}
	execute_redir(t, p, s);
}
