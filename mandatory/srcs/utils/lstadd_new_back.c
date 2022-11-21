/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_new_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:11:18 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:19:01 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_new_back(t_list **lst, void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		exit_by_error("malloc failure");
	new->content = content;
	new->next = NULL;
	ft_lstadd_back(lst, new);
}
