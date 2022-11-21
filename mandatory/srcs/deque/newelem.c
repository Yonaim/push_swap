/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newelem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:22:07 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:22:08 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_elem	*newelem(int data)
{
	t_elem	*elem;

	elem = ft_calloc(1, sizeof(t_elem));
	if (!elem)
		return (NULL);
	elem->data = data;
	return (elem);
}
