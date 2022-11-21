/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dq_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:21:30 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:21:36 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	dq_min(const t_deque *dq)
{
	t_elem	*cur;
	int		min;

	min = dq->p[TOP]->data;
	cur = dq->p[TOP];
	while (cur)
	{
		if (cur->data < min)
			min = cur->data;
		cur = cur->down;
	}
	return (min);
}
