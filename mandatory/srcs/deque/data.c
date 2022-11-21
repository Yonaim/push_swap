/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:22:37 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:22:41 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	data(const t_deque *dq, int edge, int ordinal)
{
	t_elem	*cur;

	if (dq->count == 0)
		return (FAILURE);
	if (edge == TOP)
	{
		cur = dq->p[TOP];
		while (ordinal--)
			cur = cur->down;
	}
	else
	{
		cur = dq->p[BOTTOM];
		while (ordinal--)
			cur = cur->up;
	}
	return (cur->data);
}
