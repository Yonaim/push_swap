/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:11:26 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:11:26 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ps_state(t_ps_state *ps, const t_deque *argdq)
{
	ps->a = clone_deque(argdq);
	ps->b = ft_calloc(1, sizeof(t_deque));
	if (!ps->a || !ps->b)
		exit_by_error("malloc failure");
	ps->intcnt = ps->a->count;
	ps->soln = ft_calloc(1, sizeof(t_solution));
	ps->sa = sa;
	ps->sb = sb;
	ps->ss = ss;
	ps->pa = pa;
	ps->pb = pb;
	ps->ra = ra;
	ps->rb = rb;
	ps->rr = rr;
	ps->rra = rra;
	ps->rrb = rrb;
	ps->rrr = rrr;
}
