/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:35:04 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/17 15:01:10 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"
# include "tree.h"

/*command_pipe*/
t_tree	*command_pipe(t_toks *t);
/*command_redir*/
t_tree	*command_redir(t_toks *t);
/*simple_command*/
t_tree	*simple_command(t_toks *t);
/*parser*/
t_tree	*parse(t_toks *t);

#endif
