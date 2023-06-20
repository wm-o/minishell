/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:21:14 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/19 12:42:09 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/builtins.h"
#include "../includes/hash.h"

static t_env	get_key_value(char *str)
{
	t_env	env;
	char	*index;

	ft_memset(&env, 0, sizeof(t_env));
	index = ft_strchr(str, '=');
	if (!index)
		return (env);
	env.key = ft_substr(str, 0, index - str);
	if (!env.key)
		exit(1);
	env.value = ft_strdup(index + 1);
	if (!env.value)
		exit(1);
	return (env);
}

static t_hashtable	*init_env(char **envp)
{
	int			i;
	t_hashtable	*b;
	t_env		env;
	char		*temp;
	char		*key;

	i = 0;
	b = init_hashtable();
	while (envp[i])
	{
		env = get_key_value(envp[i]);
		hashtable_insert(b, env.key, env.value);
		i++;
	}
	hashtable_delete(b, "OLDPWD");
	i = check_shlvl(find_value(b, "SHLVL"));
	temp = ft_itoa(i);
	if (!temp)
		exit(1);
	key = ft_strdup("SHLVL");
	if (!key)
		exit(1);
	hashtable_insert(b, key, temp);
	return (b);
}

static void	init_shell(t_shell *s, char **envp)
{
	ft_memset(s, 0, sizeof(t_shell));
	s->b = init_env(envp);
	tcgetattr(STDIN_FILENO, &(s->new_term));
	s->new_term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &(s->new_term));
}

int	main(int argc, char **argv, char **envp)
{
	t_shell			shell;

	signal_init(0);
	shell_intro();
	init_shell(&shell, envp);
	run_shell(&shell);
	destroy_hashtable(shell.b);
	(void)argc;
	(void)argv;
	return (0);
}
