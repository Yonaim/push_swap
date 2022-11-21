/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:11:07 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 13:20:23 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_cmds(t_list *cmds)
{
	while (cmds)
	{
		ft_putstr_fd((char *)cmds->content, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		cmds = cmds->next;
	}
}

void	ps_print_best_solution(t_list *solutions)
{
	t_solution	*best;
	t_solution	*cur;

	if (!solutions)
		exit_by_error("There's not solution");
	best = solutions->content;
	solutions = solutions->next;
	while (solutions)
	{
		cur = solutions->content;
		if (cur->cmdcnt < best->cmdcnt)
			best = cur;
		solutions = solutions->next;
	}
	print_cmds(best->cmds);
}
