/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:37:21 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/19 12:44:01 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include <stdlib.h>
# include "token.h"

typedef enum e_node_type
{
	NODE_PIPE = (1 << 0),
	NODE_REDIRECT_IN = (1 << 1),
	NODE_REDIRECT_OUT = (1 << 2),
	NODE_REDIRECT_APPEND = (1 << 3),
	NODE_REDIRECT_HEREDOC = (1 << 4),
	NODE_REDIR = NODE_REDIRECT_IN | NODE_REDIRECT_OUT | \
	NODE_REDIRECT_APPEND | NODE_REDIRECT_HEREDOC,
	NODE_CMD = (1 << 6)
}			t_node_type;

typedef struct s_tree
{
	t_node_type		type;
	char			*file;
	char			**cmd;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

/*destroy*/
void	tree_destroy(t_tree *t);
/*new_node*/
t_tree	*new_node(t_tree *left, t_tree *right);

#endif
