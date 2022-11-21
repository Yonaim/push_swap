/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_new_back_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:11:18 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 16:47:57 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
