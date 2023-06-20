/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:17:50 by wmo               #+#    #+#             */
/*   Updated: 2023/05/18 18:38:51 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hash.h"
#include "../../includes/minishell.h"

static int	hashtable_count(t_hashtable *b)
{
	int		i;
	int		count;
	t_value	*temp;

	i = 0;
	count = 0;
	while (i < BUCKET_SIZE)
	{
		if (b[i].head)
		{
			temp = b[i].head;
			while (temp)
			{
				if (temp->value)
					count++;
				temp = temp->next;
			}
		}
		i++;
	}
	return (count);
}

static char	**init_hash_arr(t_hashtable *b)
{
	char	**arr;
	int		size;

	size = hashtable_count(b);
	arr = (char **)xmalloc(sizeof(char *) * (size + 1));
	arr[size] = 0;
	return (arr);
}

static char	*join_key_value(t_value *v)
{
	char	*temp;
	char	*temp2;

	temp = ft_strjoin(v->key, "=");
	if (!temp)
		exit(1);
	temp2 = temp;
	temp = ft_strjoin(temp, v->value);
	if (!temp)
		exit(1);
	free(temp2);
	return (temp);
}

char	**hashtable_merge(t_hashtable *b)
{
	char	**arr;
	int		i;
	int		size;
	t_value	*temp;

	arr = init_hash_arr(b);
	i = 0;
	size = 0;
	while (i < BUCKET_SIZE)
	{
		if (b[i].head)
		{
			temp = b[i].head;
			while (temp)
			{
				if (temp->value)
					arr[size++] = join_key_value(temp);
				temp = temp->next;
			}
		}
		i++;
	}
	return (arr);
}
