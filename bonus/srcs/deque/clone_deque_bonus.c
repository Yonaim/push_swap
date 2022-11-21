/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_deque_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:22:51 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 16:41:36 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque_bonus.h"

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
