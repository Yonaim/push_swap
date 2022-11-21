/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:17:53 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:21:11 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_deque *dq)
{
	t_elem	*elem1;
	t_elem	*elem2;

	if (dq == NULL || dq->count <= 1)
		return ;
	elem1 = dequeue(dq, TOP);
	elem2 = dequeue(dq, TOP);
	enqueue(dq, TOP, elem1);
	enqueue(dq, TOP, elem2);
}

t_ps_state	*sa(t_ps_state *ps)
{
	swap(ps->a);
	if (ps->soln)
	{
		lstadd_new_back(&(ps->soln->cmds), (void *)SA);
		ps->soln->cmdcnt++;
	}
	return (ps);
}

t_ps_state	*sb(t_ps_state *ps)
{
	swap(ps->b);
	if (ps->soln)
	{
		lstadd_new_back(&(ps->soln->cmds), (void *)SB);
		ps->soln->cmdcnt++;
	}
	return (ps);
}

t_ps_state	*ss(t_ps_state *ps)
{
	swap(ps->a);
	swap(ps->b);
	if (ps->soln)
	{
		lstadd_new_back(&(ps->soln->cmds), (void *)SS);
		ps->soln->cmdcnt++;
	}
	return (ps);
}
