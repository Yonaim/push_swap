/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:22:29 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 16:41:36 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque_bonus.h"

t_elem	*dequeue(t_deque *dq, int edge)
{
	t_elem	*outelem;

	if ((edge != TOP && edge != BOTTOM) || (dq->count == 0))
		return (NULL);
	outelem = dq->p[edge];
	if (dq->count == 1)
		ft_memset(dq, 0, sizeof(t_deque));
	else if (edge == TOP)
	{
		dq->p[TOP] = outelem->down;
		outelem->down->up = NULL;
		dq->count--;
	}
	else if (edge == BOTTOM)
	{
		dq->p[BOTTOM] = outelem->up;
		outelem->up->down = NULL;
		dq->count--;
	}
	outelem->down = NULL;
	outelem->up = NULL;
	return (outelem);
}
