/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:15:31 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 23:29:50 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

void	close_pipeline(t_process *p)
{
	int	i;

	i = 0;
	while (i < p->pipe_len)
	{
		xclose(p->fd[i][0]);
		xclose(p->fd[i][1]);
		free(p->fd[i]);
		i++;
	}
	free(p->fd);
}

void	destroy_argv(t_process *p)
{
	int	i;

	i = 0;
	if (p->index > 0)
	{
		while (p->argv[i])
		{
			free(p->argv[i]);
			i++;
		}
	}
	if (p->argv)
	{
		free(p->argv);
		p->argv = 0;
	}
}

void	xclose(int fd)
{
	if (fd == -1)
		return ;
	if (close(fd) < 0)
		exit(1);
}

void	xdup2(int fd1, int fd2)
{
	if (fd1 != fd2)
	{
		if (dup2(fd1, fd2) < 0)
		{
			xclose(fd1);
			exit(1);
		}
	}
}

void	xpipe(int *fd)
{
	if (pipe(fd) < 0)
		exit(1);
}
