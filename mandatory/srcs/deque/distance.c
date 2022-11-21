/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:21:46 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:21:52 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	distance(const t_deque *dq, int edge, int find)
{
	int		distance;
	t_elem	*cur;

	if (dq->p[TOP]->data == find)
		return (0);
	distance = 1;
	if (edge == TOP)
	{
		cur = dq->p[TOP]->down;
		while (cur->data != find)
		{
			distance++;
			cur = cur->down;
		}
	}
	else if (edge == BOTTOM)
	{
		cur = dq->p[BOTTOM];
		while (cur->data != find)
		{
			distance++;
			cur = cur->up;
		}
	}
	return (distance);
}
