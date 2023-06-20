/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:38:36 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/18 23:52:44 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static char	*home_path(t_process *p, t_shell *s)
{
	t_value	*temp;

	temp = find_value(s->b, "HOME");
	if (!temp)
	{
		builtins_error(p, 1, "HOME not set", 1);
		return (0);
	}
	return (temp->value);
}

static char	*oldpwd_path(t_process *p, t_shell *s)
{
	t_value	*temp;

	temp = find_value(s->b, "OLDPWD");
	if (!temp)
	{
		builtins_error(p, 1, "OLDPWD not set", 1);
		return (0);
	}
	return (temp->value);
}

static int	replace_value(t_shell *s, char *old_path)
{
	char	*old_pwd;
	char	*new_pwd;
	char	*new_path;

	old_pwd = ft_strdup("OLDPWD");
	if (!old_pwd)
		exit(1);
	hashtable_insert(s->b, old_pwd, old_path);
	new_pwd = ft_strdup("PWD");
	if (!new_pwd)
		exit(1);
	new_path = getcwd(NULL, 0);
	if (!new_path)
		exit(1);
	hashtable_insert(s->b, new_pwd, new_path);
	return (0);
}

static char	*path_check(t_process *p, t_shell *s)
{
	char	*str;
	int		arg_cnt;

	arg_cnt = ft_arg_len(p);
	if (arg_cnt == 1 || !ft_strcmp(p->argv[1], "~"))
		str = home_path(p, s);
	else if (!ft_strcmp(p->argv[1], "-") || !ft_strcmp(p->argv[1], "--"))
		str = oldpwd_path(p, s);
	else
		str = p->argv[1];
	return (str);
}

int	ft_cd(t_process *p, t_shell *s)
{
	struct stat	st;
	int			value;
	char		*old_path;
	char		*str;

	str = path_check(p, s);
	if (!str)
		return (1);
	old_path = getcwd(NULL, 0);
	value = chdir(str);
	stat(str, &st);
	if (S_ISREG(st.st_mode))
	{
		free(old_path);
		return (builtins_error(p, 1, "Not a directory", 1));
	}
	if (value)
	{
		free(old_path);
		return (builtins_error(p, 1, NO_SUCH, 1));
	}
	replace_value(s, old_path);
	return (0);
}
