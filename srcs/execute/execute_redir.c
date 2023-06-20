/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:14:23 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:15:10 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"
#include "../../includes/minishell.h"

static void	check_redir_in(t_tree *t, t_process *p, t_shell *s)
{
	if (t->type & NODE_REDIRECT_IN)
	{
		if (p->infile_fd != 0)
			xclose(p->infile_fd);
		p->infile_fd = open(t->file, O_RDONLY);
		if (p->infile_fd == -1)
			p->flag |= FLAG_OPEN_ERR;
		p->file = t->file;
	}
	else if (t->type & NODE_REDIRECT_HEREDOC)
	{
		if (p->infile_fd != 0)
			xclose(p->infile_fd);
		p->infile_fd = execute_heredoc(t->file, s);
		if (p->infile_fd == -1)
			p->flag |= FLAG_OPEN_ERR;
		p->file = t->file;
	}
}

static void	check_redir_out(t_tree *t, t_process *p, t_shell *s)
{
	check_redir_in(t, p, s);
	if (p->flag & FLAG_OPEN_ERR)
		return ;
	if (t->type & NODE_REDIRECT_OUT)
	{
		if (p->outfile_fd != 1)
			xclose(p->outfile_fd);
		p->outfile_fd = open(t->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (p->outfile_fd == -1)
			p->flag |= FLAG_OPEN_ERR;
		p->file = t->file;
	}
	else if (t->type & NODE_REDIRECT_APPEND)
	{
		if (p->outfile_fd != 1)
			xclose(p->outfile_fd);
		p->outfile_fd = open(t->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (p->outfile_fd == -1)
			p->flag |= FLAG_OPEN_ERR;
		p->file = t->file;
	}
}

static int	cmd_count(t_tree *t)
{
	int	is_cmd;

	if (!t)
		return (0);
	is_cmd = 0;
	if (t->type & NODE_CMD)
	{
		while (t->cmd[is_cmd])
			is_cmd++;
	}
	is_cmd += cmd_count(t->left);
	is_cmd += cmd_count (t->right);
	return (is_cmd);
}

static void	init_argv(t_tree *t, t_process *p)
{
	int	len;

	len = cmd_count(t);
	p->argv = (char **)xmalloc(sizeof(char *) * (len + 1));
	p->argv[len] = 0;
}

void	execute_redir(t_tree *t, t_process *p, t_shell *s)
{
	if (!t)
		return ;
	if (!p->argv)
		init_argv(t, p);
	if (t->type & NODE_REDIR)
	{
		p->flag |= FLAG_REDIR;
		if (!(p->flag & FLAG_OPEN_ERR))
			check_redir_out(t, p, s);
		execute_simple_command(t->left, p);
		execute_redir(t->right, p, s);
	}
	else if (t->type & NODE_CMD)
		execute_simple_command(t, p);
	if (!(p->flag & FLAG_EXECUTED))
	{
		p->flag |= FLAG_EXECUTED;
		execute_process(t, p, s);
	}
}
