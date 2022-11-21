/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_deviation_guarant.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:17:57 by yona              #+#    #+#             */
/*   Updated: 2022/11/11 00:21:36 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_to_b(t_ps_state *ps, int deviation)
{
	int				pass;
	const t_deque	*a = ps->a;

	pass = 0;
	while (a->count > 0)
	{
		if (data(a, TOP, 0) <= pass)
		{
			pb(ps)->rb(ps);
			pass++;
		}
		else if (data(a, TOP, 0) <= deviation + pass)
		{
			pb(ps);
			pass++;
		}
		else
		{
			if (data(a, BOTTOM, 0) <= deviation + pass)
				rra(ps);
			else
				ra(ps);
		}
	}
}

static void	b_to_a(t_ps_state *ps, t_deque *a, t_deque *b)
{
	int	max;

	while (b->count > 0)
	{
		max = dq_max(b);
		while (data(b, TOP, 0) != max)
		{
			if (data(b, TOP, 0) == max - 1)
				pa(ps);
			if (data(a, TOP, 0) == max - 1 && data(b, TOP, 0) == max - 2)
				pa(ps)->ra(ps);
			if (closest_edge(b, max) == TOP)
				rb(ps);
			else
				rrb(ps);
		}
		pa(ps);
		if (a->count >= 2 && data(a, TOP, 1) == max - 1)
			sa(ps);
		if (a->count >= 3 && data(a, BOTTOM, 0) == max - 2)
			rra(ps);
	}
}

static int	find_best_deviation(t_deque *argdq, int intcnt)
{
	t_ps_state		copied;
	const int		max_deviation = intcnt * 0.2;
	int				cur_deviation;
	unsigned int	min_cmdcnt;

	cur_deviation = 5;
	min_cmdcnt = INT_MAX;
	while (cur_deviation < max_deviation)
	{
		init_ps_state(&copied, argdq);
		a_to_b(&copied, cur_deviation);
		b_to_a(&copied, copied.a, copied.b);
		destroy_deque(copied.a);
		destroy_deque(copied.b);
		if (copied.soln->cmdcnt < min_cmdcnt)
			min_cmdcnt = copied.soln->cmdcnt;
		else
			break ;
		cur_deviation += 5;
	}
	return (cur_deviation);
}

void	sort_deviation_guarant(t_ps_state *ps)
{
	a_to_b(ps, find_best_deviation(ps->a, ps->intcnt));
	b_to_a(ps, ps->a, ps->b);
}
