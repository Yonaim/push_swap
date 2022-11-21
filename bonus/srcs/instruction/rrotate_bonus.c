/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:17:51 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 16:44:29 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rrotate(t_deque *dq)
{
	t_elem	*elem;

	if (dq == NULL || dq->count <= 1)
		return ;
	elem = dequeue(dq, BOTTOM);
	enqueue(dq, TOP, elem);
}

t_ps_state	*rra(t_ps_state *ps)
{
	rrotate(ps->a);
	if (ps->soln)
	{
		lstadd_new_back(&(ps->soln->cmds), (void *)RRA);
		ps->soln->cmdcnt++;
	}
	return (ps);
}

t_ps_state	*rrb(t_ps_state *ps)
{
	rrotate(ps->b);
	if (ps->soln)
	{
		lstadd_new_back(&(ps->soln->cmds), (void *)RRB);
		ps->soln->cmdcnt++;
	}
	return (ps);
}

t_ps_state	*rrr(t_ps_state *ps)
{
	rrotate(ps->a);
	rrotate(ps->b);
	if (ps->soln)
	{
		lstadd_new_back(&(ps->soln->cmds), (void *)RRR);
		ps->soln->cmdcnt++;
	}
	return (ps);
}
