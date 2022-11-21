/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_edge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:22:44 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:22:46 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	closest_edge(const t_deque *dq, int find)
{
	if (distance(dq, TOP, find) \
		< distance(dq, BOTTOM, find))
		return (TOP);
	else
		return (BOTTOM);
}
