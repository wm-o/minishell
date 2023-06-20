/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:34:44 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/19 12:43:46 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"
# include "tree.h"

typedef enum e_flag
{
	FLAG_READ_PIPE = (1 << 0),
	FLAG_WRITE_PIPE = (1 << 1),
	FLAG_REDIR = (1 << 2),
	FLAG_EXECUTED = (1 << 3),
	FLAG_OPEN_ERR = (1 << 4)
}			t_flag;

typedef struct s_process
{
	char	**argv;
	char	*file;
	int		index;
	int		infile_fd;
	int		outfile_fd;
	int		pipe_in_fd;
	int		pipe_out_fd;
	int		out;
	int		in;
	int		**fd;
	int		pipe_len;
	int		cur;
	t_flag	flag;
}			t_process;

/*cmd*/
void	exec_cmd(t_tree *t, t_process *p, t_shell *s);
/*heredoc*/
int		execute_heredoc(char *eof, t_shell *s);
/*pipe*/
void	set_pipe(t_tree *t, t_process *p, t_shell *s);
void	execute_pipe(t_tree *t, t_process *p, t_shell *s);
/*process_utils*/
void	new_pid(t_shell *s);
void	wait_child_process(t_shell *s);
void	close_other_pipes(t_process *p);
void	dup_process_fd(t_process *p);
int		xdup(int fd);
/*process*/
void	execute_builtin(t_tree *t, t_process *p, t_shell *s);
void	execute_process(t_tree *t, t_process *p, t_shell *s);
/*redir*/
void	execute_redir(t_tree *t, t_process *p, t_shell *s);
/*simple*/
void	execute_simple_command(t_tree *t, t_process *p);
/*utils*/
void	close_pipeline(t_process *p);
void	destroy_argv(t_process *p);
void	xclose(int fd);
void	xdup2(int fd1, int fd2);
void	xpipe(int *fd);
/*execute*/
void	execute(t_tree *t, t_shell *s);

#endif
