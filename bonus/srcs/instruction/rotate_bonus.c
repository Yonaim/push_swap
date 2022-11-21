/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:17:45 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 16:44:29 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_deque *dq)
{
	t_elem	*elem;

	if (dq == NULL || dq->count <= 1)
		return ;
	elem = dequeue(dq, TOP);
	enqueue(dq, BOTTOM, elem);
}

t_ps_state	*ra(t_ps_state *ps)
{
	rotate(ps->a);
	if (ps->soln)
	{
		lstadd_new_back(&(ps->soln->cmds), (void *)RA);
		ps->soln->cmdcnt++;
	}
	return (ps);
}

t_ps_state	*rb(t_ps_state *ps)
{
	rotate(ps->b);
	if (ps->soln)
	{
		lstadd_new_back(&(ps->soln->cmds), (void *)RB);
		ps->soln->cmdcnt++;
	}
	return (ps);
}

t_ps_state	*rr(t_ps_state *ps)
{
	rotate(ps->a);
	rotate(ps->b);
	if (ps->soln)
	{
		lstadd_new_back(&(ps->soln->cmds), (void *)RR);
		ps->soln->cmdcnt++;
	}
	return (ps);
}
