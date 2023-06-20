/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:09:18 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 22:49:17 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"
#include "../../includes/expand.h"

static char	*expand_line(char *line, t_shell *s)
{
	char	*temp;
	int		i;

	temp = (char *)xmalloc(1);
	temp[0] = '\0';
	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
			temp = parse_dollar(line, temp, &i, s->b);
		else
		{
			temp = char_append(temp, line[i]);
			i++;
		}
	}
	free(line);
	return (temp);
}

static void	heredoc_child(char *eof, t_shell *s, int *fd)
{
	char	*line;

	signal_init(2);
	xclose(fd[0]);
	while (1)
	{
		line = readline(">");
		if (!line)
			exit(0);
		if (!ft_strcmp(line, eof))
			break ;
		line = expand_line(line, s);
		ft_putendl_fd(line, fd[1]);
		free(line);
	}
	xclose(fd[1]);
	if (line)
		free(line);
	exit(0);
}

int	execute_heredoc(char *eof, t_shell *s)
{
	int			fd[2];
	int			pid;
	int			status;
	extern int	g_status;

	xpipe(fd);
	signal_init(3);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
		heredoc_child(eof, s, fd);
	xclose(fd[1]);
	waitpid(pid, &status, 0);
	signal_init(0);
	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status);
	return (fd[0]);
}
