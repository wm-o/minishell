/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:29:11 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/18 22:51:41 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shell_intro(void)
{
	printf("\033[0;36m");
	printf("----- ----- ----- ----- -----\n");
	printf("Project	:	Minishell V.6\n");
	printf("Develop	:	wmo / seojulee\n");
	printf("Process	:	%s\n", SHELL_NAME);
	printf("Version	:	1.0_Alpha\n");
	printf("----- ----- ----- ----- -----\n");
}
