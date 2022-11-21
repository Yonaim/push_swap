/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:18:06 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:36:54 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 
#include "sort_greedy.h" 

static int	find_proper_position(t_deque *a, int target)
{
	int		pos;
	t_elem	*prev;
	t_elem	*next;

	if (a->count == 0)
		return (0);
	if (target < dq_min(a))
		return (distance(a, TOP, dq_min(a)));
	else if (target > dq_max(a))
		return (distance(a, TOP, dq_max(a)) + 1);
	pos = 0;
	prev = a->p[TOP];
	next = a->p[TOP]->down;
	while (next)
	{
		pos++;
		if (prev->data < target && target < next->data)
			break ;
		prev = prev->down;
		next = next->down;
	}
	if (prev == a->p[BOTTOM])
		pos = 0;
	return (pos);
}

static int	cost_to_a_proper(t_ps_state *ps, int target, int logic)
{
	if (logic == RA_RB || logic == RA_RRB)
		return (find_proper_position(ps->a, target));
	else
		return (ps->a->count - find_proper_position(ps->a, target));
}

static int	cost_to_b_edge(t_ps_state *ps, int target, int logic)
{
	if (logic == RA_RB || logic == RRA_RB)
		return (distance(ps->b, TOP, target));
	else
		return (distance(ps->b, BOTTOM, target));
}

int	compute_greedy_cost(t_ps_state *ps, t_elem *target, int logic)
{
	int			total;
	const int	cost_b = cost_to_b_edge(ps, target->data, logic);
	const int	cost_a = cost_to_a_proper(ps, target->data, logic);

	if (logic == RA_RB || logic == RRA_RRB)
		total = max(cost_b, cost_a);
	else
		total = cost_b + cost_a;
	return (total);
}

void	complete_greedy_cost(t_ps_state *ps, t_elem *target, \
						int logic, t_greedy_cost *cost)
{
	cost->target = target;
	cost->cost_b = cost_to_b_edge(ps, target->data, logic);
	cost->cost_a = cost_to_a_proper(ps, target->data, logic);
	cost->logic = logic;
	if (logic == RA_RB || logic == RRA_RRB)
		cost->total = max(cost->cost_b, cost->cost_a);
	else
		cost->total = cost->cost_b + cost->cost_a;
}
