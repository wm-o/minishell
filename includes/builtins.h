/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:01:05 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/19 12:44:03 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/libft.h"
# include "minishell.h"
# include "debug.h"
# include "execute.h"
# include "hash.h"

typedef struct s_merge
{
	char	**temp;
	int		l;
	int		m;
	int		t;
}			t_merge;

/*builtins_function*/
int		ft_cd(t_process *p, t_shell *s);
int		ft_echo(t_process *p);
int		ft_env(t_process *p, t_shell *s);
int		ft_exit(t_process *p);
int		ft_export(t_process *p, t_shell *s);
int		ft_pwd(void);
int		ft_unset(t_process *p, t_shell *s);
/*utils*/
int		ft_arg_len(t_process *p);
int		ft_key_len(char *str);
int		key_valid(char *key);
void	bubble_sort(char **str, int size);
void	merge_sort(char **arr, int left, int right);
/*builtins*/
int		is_builtin(t_process *p, t_shell *s);
int		builtins_check(t_process *p, t_shell *s);
int		builtins_error(t_process *p, int index, char *msg, int err_code);

#endif
