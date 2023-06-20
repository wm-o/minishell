/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:03:49 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/19 12:49:57 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signal_init(int child_flag)
{
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		exit(SIGQUIT + 128);
	if (signal(SIGTERM, SIG_IGN) == SIG_ERR)
		exit(SIGTERM + 128);
	if (child_flag == 0)
		if (signal(SIGINT, signal_handler) == SIG_ERR)
			exit(SIGINT + 128);
	if (child_flag == 1)
		if (signal(SIGINT, signal_handler_child) == SIG_ERR)
			exit(SIGINT + 128);
	if (child_flag == 2)
		if (signal(SIGINT, signal_handler_heredoc) == SIG_ERR)
			exit(SIGINT + 128);
	if (child_flag == 3)
		if (signal(SIGINT, SIG_IGN) == SIG_ERR)
			exit(SIGINT + 128);
}

void	signal_handler(int signo)
{
	if (SIGINT != signo)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
	g_status = 1;
}

void	signal_handler_child(int signo)
{
	if (SIGINT != signo)
		return ;
	exit(SIGINT + 128);
}

void	signal_handler_heredoc(int signo)
{
	if (SIGINT != signo)
		return ;
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
	write(STDOUT_FILENO, "\n", 1);
	exit(1);
}
