/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dq_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:21:41 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:21:42 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	dq_max(const t_deque *dq)
{
	t_elem	*cur;
	int		max;

	max = dq->p[TOP]->data;
	cur = dq->p[TOP];
	while (cur)
	{
		if (cur->data > max)
			max = cur->data;
		cur = cur->down;
	}
	return (max);
}
