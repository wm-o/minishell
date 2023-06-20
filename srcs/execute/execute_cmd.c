/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:34:24 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/18 18:40:48 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"
#include "../../includes/debug.h"

static char	*check_path(t_process *p, char **path)
{
	char	*slash;
	char	*temp;

	if (!path)
		return (ft_strdup(""));
	while (*path)
	{
		slash = ft_strjoin(*path, "/");
		if (!slash)
			exit(1);
		temp = ft_strjoin(slash, p->argv[0]);
		if (!temp)
			exit(1);
		free(slash);
		if (access(temp, F_OK) != -1)
			return (temp);
		free(temp);
		path++;
	}
	return (ft_strdup(""));
}

static char	**check_value(t_process *p, t_shell *s)
{
	t_value	*v;
	char	**path;

	v = find_value(s->b, "PATH");
	if (!v || !v->value)
		return (0);
	path = ft_split(v->value, ':');
	if (!v)
		exit(1);
	(void)p;
	return (path);
}

static void	execute_absolute(t_process *p, t_shell *s, char **env)
{
	struct stat	st;

	execve(p->argv[0], p->argv, env);
	if (stat(p->argv[0], &st) == -1)
		cmd_error(p->argv[0], NO_SUCH, 127, s);
	else if (!(S_IXUSR & st.st_mode))
		cmd_error(p->argv[0], PERMISSION_DENIED, 126, s);
	else if (S_ISDIR(st.st_mode))
		cmd_error(p->argv[0], IS_DIRECTORY, 126, s);
}

void	exec_cmd(t_tree *t, t_process *p, t_shell *s)
{
	char		*cmd;
	char		**path;
	char		**env;
	struct stat	st;

	env = hashtable_merge(s->b);
	if (ft_strchr(p->argv[0], '/'))
		execute_absolute(p, s, env);
	path = check_value(p, s);
	cmd = check_path(p, path);
	execve(cmd, p->argv, env);
	if (stat(cmd, &st) == -1)
		command_error(p->argv[0], s);
	else if (!(S_IXUSR & st.st_mode))
		cmd_error(p->argv[0], PERMISSION_DENIED, 126, s);
	else if (S_ISDIR(st.st_mode))
		cmd_error(p->argv[0], IS_DIRECTORY, 126, s);
	(void)t;
}
