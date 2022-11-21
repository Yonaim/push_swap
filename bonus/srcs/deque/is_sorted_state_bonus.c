/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_state_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:21:58 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 16:41:36 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque_bonus.h"

int	is_sorted_state(const t_deque *dq, const unsigned int intcnt)
{
	t_elem	*cur;

	if (dq->count != intcnt)
		return (FALSE);
	cur = dq->p[TOP];
	while (cur->down)
	{
		if ((cur->data) > (cur->down->data))
			return (FALSE);
		cur = cur->down;
	}
	return (TRUE);
}
