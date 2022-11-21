/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:11:04 by yona              #+#    #+#             */
/*   Updated: 2022/11/11 00:43:44 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_solution	*get_solution(const t_deque *argdq, const t_ps_sort sort)
{
	t_ps_state	ps;

	init_ps_state(&ps, argdq);
	(*sort)(&ps);
	if (is_sorted_state(ps.a, ps.intcnt) == FALSE)
	{
		ft_lstclear(&ps.soln->cmds, NULL);
		free(ps.soln);
		ps.soln = NULL;
	}
	destroy_deque(ps.a);
	destroy_deque(ps.b);
	return (ps.soln);
}

t_list	*ps_solve(t_list **solutions, const t_deque *argdq)
{
	t_solution		*solved;
	const t_ps_sort	sort[] = {
		sort_five_or_below,
		sort_deviation_guarant,
		sort_greedy,
		NULL
	};
	int				idx;

	*solutions = NULL;
	idx = 0;
	while (sort[idx])
	{
		solved = get_solution(argdq, sort[idx]);
		if (solved)
			lstadd_new_back(solutions, (void *)solved);
		idx++;
	}
	return (*solutions);
}
