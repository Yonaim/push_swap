/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_deque.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:22:20 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:22:26 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	destroy_deque(t_deque *dq)
{
	t_elem	*cur;	
	t_elem	*next;

	cur = dq->p[TOP];
	while (cur)
	{
		next = cur->down;
		free(cur);
		cur = next;
	}
	free(dq);
}
