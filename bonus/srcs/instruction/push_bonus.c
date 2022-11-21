/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:17:42 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 16:44:29 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	push(t_deque *from, t_deque *to)
{
	t_elem	*elem;

	if (from == NULL || from->count == 0)
		return ;
	elem = dequeue(from, TOP);
	enqueue(to, TOP, elem);
}

t_ps_state	*pa(t_ps_state *ps)
{
	push(ps->b, ps->a);
	if (ps->soln)
	{
		lstadd_new_back(&(ps->soln->cmds), (void *)PA);
		ps->soln->cmdcnt++;
	}
	return (ps);
}

t_ps_state	*pb(t_ps_state *ps)
{
	push(ps->a, ps->b);
	if (ps->soln)
	{
		lstadd_new_back(&(ps->soln->cmds), (void *)PB);
		ps->soln->cmdcnt++;
	}
	return (ps);
}
