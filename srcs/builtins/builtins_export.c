/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:38:27 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/19 12:46:10 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static void	dbp_free(char **str, size_t len)
{
	free(str[len]);
	while (len)
		free(str[--len]);
	free(str);
}

static char	*get_str(char *str)
{
	char	*temp;

	if (!str || str[0] == '\0')
		return (0);
	if (str[0] == '=')
		str++;
	temp = ft_strdup(str);
	if (!temp)
		exit(1);
	return (temp);
}

static char	**init_key_arr(t_shell *s, int env_len)
{
	t_value	*temp;
	char	**key_arr;
	int		i;

	key_arr = (char **)malloc(sizeof(char *) * (env_len + 1));
	if (!key_arr)
		exit(1);
	key_arr[env_len--] = NULL;
	i = -1;
	while (++i < BUCKET_SIZE)
	{
		if (s->b[i].head)
		{
			temp = s->b[i].head;
			while (temp)
			{
				key_arr[env_len--] = get_str(temp->key);
				if (env_len < 0)
					return (key_arr);
				temp = temp->next;
			}
		}
	}
	return (0);
}

static int	print_sort_env(t_shell *s)
{
	t_value	*temp;
	char	**key_arr;
	int		env_len;
	int		i;

	env_len = hashtable_len(s->b);
	key_arr = init_key_arr(s, env_len);
	bubble_sort(key_arr, env_len);
	i = -1;
	while (++i < env_len)
	{
		temp = find_value(s->b, key_arr[i]);
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(temp->key, 1);
		if (temp->value)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(temp->value, 1);
			ft_putchar_fd('\"', 1);
		}
		ft_putchar_fd('\n', 1);
	}
	dbp_free(key_arr, env_len);
	return (0);
}

int	ft_export(t_process *p, t_shell *s)
{
	char	*key;
	char	*value;
	int		key_len;
	int		i;

	if (ft_arg_len(p) == 1)
		return (print_sort_env(s));
	i = 0;
	while (p->argv[++i])
	{
		key_len = ft_key_len(p->argv[i]);
		key = ft_substr(p->argv[i], 0, key_len);
		if (!key)
			exit(1);
		if (!key_valid(key))
		{
			free(key);
			builtins_error(p, i, NOT_VALID_ID, 1);
			continue ;
		}
		value = get_str(&p->argv[i][key_len]);
		hashtable_insert(s->b, key, value);
	}
	return (0);
}
