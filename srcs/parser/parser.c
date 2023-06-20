/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:21:52 by wmo               #+#    #+#             */
/*   Updated: 2023/05/16 10:22:23 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/*
 *		BNF ::=
 *
 *		<command_pipe>	::=	<command_redir>
 *						|	<command_redir> '|' <command_pipe>
 *
 *		<command_redir>	::=	<simple_cmd>
 *						|	<io_redir>			<command_redir>
 *
 *		<io_redir>		::=	"<<"	"eof"
 *						|	">>"	"file"
 *						|	"<"		"file"
 *						|	">"		"file"
 *		<simple_cmd>	::= "cmd"
 *						|	"opt"
 *						|	'NULL'
 *
 * */

t_tree	*parse(t_toks *t)
{
	t_tree	*tree;

	t->cur = t->head;
	tree = command_pipe(t);
	return (tree);
}
