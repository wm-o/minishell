/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:35:43 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/17 13:37:09 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_token_type
{
	TOK_NONE = 0,
	TOK_STR = (1 << 0),
	TOK_RDI_INPUT = (1 << 1),
	TOK_RDI_APPEND = (1 << 2),
	TOK_RDI_OUTPUT = (1 << 3),
	TOK_RDI_HEREDOC = (1 << 4),
	TOK_PIPE = (1 << 5),
	TOK_END = (1 << 6),
	TOK_EOF = (1 << 7),
	TOK_RDIR = TOK_RDI_INPUT | TOK_RDI_APPEND | \
	TOK_RDI_HEREDOC | TOK_RDI_OUTPUT,
	TOK_ALL = ~0
}			t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*buf;
}					t_token;

#endif
