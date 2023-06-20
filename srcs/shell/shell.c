/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:23:26 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 23:16:37 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/lexer.h"
#include "../../includes/parser.h"
#include "../../includes/expand.h"
#include "../../includes/execute.h"
#include "../../includes/debug.h"

static char	*get_line(void)
{
	char	*line;
	char	*divide;

	line = readline("$ ");
	if (!line)
	{
		write(1, "exit\n", 5);
		exit(0);
	}
	add_history(line);
	divide = ft_strtrim(line, " \t");
	free(line);
	if (!divide)
		exit(1);
	return (divide);
}

static int	check_syntax_error(t_toks *tokens, t_tree *tree, char *line)
{
	if (line[0] == '\0')
	{
		free(line);
		lexer_destroy(tokens->head);
		return (1);
	}
	if (tokens->syntax_error)
	{
		ft_putstr_fd(SHELL_NAME, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd("syntax error", 2);
		free(line);
		lexer_destroy(tokens->head);
		tree_destroy(tree);
		return (1);
	}
	return (0);
}

void	run_shell(t_shell *s)
{
	char	*line;
	t_toks	tokens;
	t_tree	*tree;

	while (1)
	{
		line = get_line();
		lexer(&tokens, line, s);
		expand(tokens.head, &tokens);
		tree = parse(&tokens);
		if (check_syntax_error(&tokens, tree, line))
			continue ;
		lexer_destroy(tokens.head);
		execute(tree, s);
		tree_destroy(tree);
		free(line);
	}
}
