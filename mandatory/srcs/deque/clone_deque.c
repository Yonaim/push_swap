/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_deque.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:22:51 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:22:55 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque	*clone_deque(const t_deque *ori)
{
	t_deque	*clone;
	t_elem	*cur;

	clone = ft_calloc(1, sizeof(t_deque));
	cur = ori->p[TOP];
	while (cur)
	{
		enqueue(clone, BOTTOM, newelem(cur->data));
		cur = cur->down;
	}
	return (clone);
}
