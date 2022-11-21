/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_below.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:18:00 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:11:37 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_ps_state *ps)
{
	if (data(ps->a, TOP, 0) > data(ps->a, TOP, 1))
		sa(ps);
}

static void	sort_three(t_ps_state *ps)
{
	const int	max = ps->intcnt;

	if (data(ps->a, TOP, 0) == max)
		ra(ps);
	else if (data(ps->a, TOP, 1) == max)
		sa(ps)->ra(ps);
	else if (data(ps->a, TOP, 2) == max)
		;
	sort_two(ps);
}

static void	sort_four(t_ps_state *ps)
{
	const int	min = ps->b->count + 1;

	if (data(ps->a, TOP, 0) == min)
		pb(ps);
	else if (data(ps->a, TOP, 1) == min)
		sa(ps)->pb(ps);
	else if (data(ps->a, TOP, 2) == min)
		ra(ps)->ra(ps)->pb(ps);
	else if (data(ps->a, TOP, 3) == min)
		rra(ps)->pb(ps);
	sort_three(ps);
	pa(ps);
}

static void	sort_five(t_ps_state *ps)
{
	const int	min = ps->b->count + 1;

	if (data(ps->a, TOP, 0) == min)
		pb(ps);
	else if (data(ps->a, TOP, 1) == min)
		sa(ps)->pb(ps);
	else if (data(ps->a, TOP, 2) == min)
		ra(ps)->ra(ps)->pb(ps);
	else if (data(ps->a, TOP, 3) == min)
		rra(ps)->rra(ps)->pb(ps);
	else if (data(ps->a, TOP, 4) == min)
		rra(ps)->pb(ps);
	sort_four(ps);
	pa(ps)->pa(ps);
}

void	sort_five_or_below(t_ps_state *ps)
{
	if (ps->intcnt == 2)
		sort_two(ps);
	else if (ps->intcnt == 3)
		sort_three(ps);
	else if (ps->intcnt == 4)
		sort_four(ps);
	else if (ps->intcnt == 5)
		sort_five(ps);
}
