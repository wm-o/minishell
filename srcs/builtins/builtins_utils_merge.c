/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:33:47 by seojulee          #+#    #+#             */
/*   Updated: 2023/05/17 13:33:48 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

static void	init_merge_sort(t_merge *st, int left, int right)
{
	ft_memset(st, 0, sizeof(t_merge));
	st->l = left;
	st->t = left;
	st->m = (left + right) / 2 + 1;
	st->temp = (char **)xmalloc(sizeof(char *) * (right + 1));
}

static void	merge(char **arr, int left, int right)
{
	t_merge	st;
	int		mid;

	mid = (left + right) / 2;
	init_merge_sort(&st, left, right);
	while (st.l <= mid && st.m <= right)
	{
		if (ft_strcmp(arr[st.l], arr[st.m]) < 0)
			st.temp[st.t++] = arr[st.l++];
		else
			st.temp[st.t++] = arr[st.m++];
	}
	while (st.l <= mid)
		st.temp[st.t++] = arr[st.l++];
	while (st.m <= right)
		st.temp[st.t++] = arr[st.m++];
	while (left <= right)
	{
		arr[left] = st.temp[left];
		left++;
	}
	free(st.temp);
	st.temp = 0;
}

void	merge_sort(char **arr, int left, int right)
{
	int	mid;

	if (left >= right)
		return ;
	mid = (left + right) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, right);
}
