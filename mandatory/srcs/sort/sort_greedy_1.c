/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:18:04 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:39:36 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 
#include "sort_greedy.h" 

static void	find_lowest_cost_elem(t_ps_state *ps, t_greedy_cost *lowest)
{
	t_elem		*cur;
	const int	logic[4] = {RA_RB, RRA_RB, RA_RRB, RRA_RRB};
	int			i;

	lowest->total = INT_MAX;
	cur = ps->b->p[TOP];
	while (cur)
	{
		i = 0;
		while (i < 4)
		{
			if (compute_greedy_cost(ps, cur, logic[i]) < lowest->total)
				complete_greedy_cost(ps, cur, logic[i], lowest);
			i++;
		}
		cur = cur->down;
	}
}

static void	a_to_b(t_ps_state *ps, t_deque *a, t_deque *b)
{
	int	prev_pivot;
	int	curr_pivot;
	int	step;

	step = 3;
	curr_pivot = 0;
	while (step)
	{
		prev_pivot = curr_pivot;
		curr_pivot = ps->intcnt / step;
		while (b->count < (unsigned int)ps->intcnt / step)
		{
			if (data(a, TOP, 0) <= (prev_pivot + curr_pivot) / 2)
				pb(ps);
			else if (data(a, TOP, 0) <= curr_pivot)
				pb(ps)->rb(ps);
			else
				ra(ps);
		}
		step--;
	}
}

static void	b_to_a(t_ps_state *ps)
{
	t_greedy_cost		cur;
	const t_ps_instr	cmd[4][3] = {
	[RA_RB] = {ra, rb, rr}, [RRA_RB] = {rra, rb},
	[RA_RRB] = {ra, rrb}, [RRA_RRB] = {rra, rrb, rrr}};

	while (ps->b->count > 0)
	{
		find_lowest_cost_elem(ps, &cur);
		if (cur.logic == RA_RB || cur.logic == RRA_RRB)
		{
			exec_cmd_repeat(ps, cmd[cur.logic][2], \
								min(cur.cost_a, cur.cost_b));
			exec_cmd_repeat(ps, cmd[cur.logic][(cur.cost_b > cur.cost_a)], \
					cur.total - min(cur.cost_a, cur.cost_b));
		}
		else
		{
			exec_cmd_repeat(ps, cmd[cur.logic][1], cur.cost_b);
			exec_cmd_repeat(ps, cmd[cur.logic][0], cur.cost_a);
		}
		pa(ps);
	}
}

static void	align_a(t_ps_state *ps, t_deque *a)
{
	int			min_data;
	t_ps_instr	cmd;

	min_data = dq_min(a);
	if (closest_edge(a, min_data) == TOP)
		cmd = ra;
	else
		cmd = rra;
	while (a->p[TOP]->data != min_data)
		cmd(ps);
}

void	sort_greedy(t_ps_state *ps)
{
	a_to_b(ps, ps->a, ps->b);
	b_to_a(ps);
	align_a(ps, ps->a);
}
