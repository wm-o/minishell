/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:34:56 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/19 12:42:51 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include <stdlib.h>

# define BUCKET_SIZE 5381

typedef unsigned long long	t_ll;

typedef struct s_value
{
	char					*key;
	char					*value;
	struct s_value			*prev;
	struct s_value			*next;
}							t_value;

typedef struct s_hashtable
{
	t_value					*head;
	t_value					*tail;
	int						size;
}							t_hashtable;

/*hash_fuction*/
int				hash_function(char *key);
/*delete*/
void			hashtable_delete(t_hashtable *b, char *key);
/*destroy*/
void			destroy_value(t_value *v);
void			destroy_values(t_value *v);
void			destroy_hashtable(t_hashtable *b);
/*find*/
t_value			*find_value(t_hashtable *b, char *key);
/*insert*/
void			hashtable_insert(t_hashtable *b, char *key, char *value);
/*len*/
int				hashtable_len(t_hashtable *b);
/*merge*/
char			**hashtable_merge(t_hashtable *b);
/*print*/
void			hashtable_print(t_hashtable *b);
/*hashtable*/
t_hashtable		*init_hashtable(void);

#endif
