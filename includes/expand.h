/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:34:54 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/17 14:30:58 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "hash.h"
# include "lexer.h"

/*backslash*/
char	*parse_backslash(char *str, char *temp, int *i, t_toks *tokens);
/*quote*/
char	*parse_quote(char *str, char *temp, int *i, t_toks *tokens);
/*utils*/
char	*char_append(char *s, char c);
char	*str_append(char *s1, char *s2);
/*expand*/
void	expand(t_token_list *t, t_toks *tokens);
/*parse_dollar*/
char	*parse_dollar(char *str, char *temp, int *i, t_hashtable *b);

#endif
