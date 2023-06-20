/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:34:58 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/17 14:59:02 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../libft/libft.h"
# include "minishell.h"
# include "hash.h"
# include "token.h"

typedef enum s_state
{
	STATE_GENERAL,
	STATE_BLANK,
	STATE_EOF,
	STATE_QUOTE,
	STATE_REDIR,
	STATE_DIVIDE,
	STATE_STR,
	STATE_END,
	STATE_ERR
}	t_state;

typedef struct s_token_list
{
	t_token				data;
	struct s_token_list	*next;
}	t_token_list;

typedef struct s_toks
{
	t_token_list	*head;
	t_token_list	*cur;
	t_token_list	*tail;
	t_hashtable		*b;
	int				state;
	char			*str;
	int				start;
	int				pos;
	int				len;
	int				syntax_error;
}	t_toks;

/*blank*/
t_state			lexer_blank(t_toks *t);
/*delete*/
void			delete_space(t_token *t);
void			delete_s_quote(t_token *t);
void			delete_d_quote(t_token *t);
/*destroy*/
void			lexer_destroy(t_token_list *t);
/*divide*/
t_state			lexer_divide(t_toks *t);
/*eof*/
t_state			lexer_eof(t_toks *t);
/*general*/
t_state			lexer_general(t_toks *t);
/*new_token*/
void			new_token(t_toks *t, t_token_type type);
/*quete*/
t_state			lexer_quote(t_toks *t);
/*redirect*/
t_state			lexer_d_redir(t_toks *t, char cur);
t_state			lexer_redirect(t_toks *t);
/*str*/
t_state			lexer_str(t_toks *t);
/*utils*/
int				ft_isquote(int c);
int				ft_isnull(int c);
int				ft_isredir(int c);
int				ft_ispipe(int c);
int				ft_isblank(int c);
int				divide_case(int c);
char			cur_tok(t_toks *t);
char			next_tok(t_toks *t);
void			push_back(t_toks *t, t_token_list *n);
t_token_list	*new_list(t_token t);
/*lexer*/
void			lexer(t_toks *t, char *str, t_shell *s);

#endif
