/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:01:05 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/19 12:43:37 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "hash.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

# define SHELL_NAME "Minishell"

int	g_status;

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

typedef struct s_pid_list
{
	int					pid;
	struct s_pid_list	*next;
}	t_pid_list;

typedef struct s_queue
{
	t_pid_list	*head;
	t_pid_list	*tail;
}	t_queue;

typedef struct s_shell
{
	struct termios	new_term;
	t_hashtable		*b;
	t_queue			pid_q;
}	t_shell;

/*intro.c*/
void	shell_intro(void);
/*shell.c*/
void	run_shell(t_shell *s);
/*signal.c*/
void	signal_init(int child_flag);
void	signal_handler(int signo);
void	signal_handler_child(int signo);
void	signal_handler_heredoc(int signo);
/* utils */
int		ft_strcmp(char *s1, char *s2);
int		check_shlvl(t_value *value);
void	*xmalloc(size_t size);
void	destroy_pid(t_pid_list	*p);

#endif
