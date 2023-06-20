/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:34:49 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/19 14:53:06 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "minishell.h"
# include "execute.h"
# include "expand.h"
# include "lexer.h"
# include "parser.h"
# include "tree.h"

# define CMD_NOT_FOUND "command not found"
# define NO_SUCH "No such file or directory"
# define NOT_VALID_ID "not a valid identifier"
# define TOO_MANY_ARGS "too many arguments"
# define IS_DIRECTORY "is a directory"
# define PERMISSION_DENIED "Permission denied"

/*debug*/
void	cmd_error(char *cmd, char *msg, int status, t_shell *s);
void	command_error(char *cmd, t_shell *s);
void	check_open_error(t_process *p, t_shell *s);
int		check_open_error_builtin(t_process *p, t_shell *s);

#endif
