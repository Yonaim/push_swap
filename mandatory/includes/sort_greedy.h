/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:28:58 by yeonhkim          #+#    #+#             */
/*   Updated: 2022/11/12 15:32:35 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_GREEDY_H
# define SORT_GREEDY_H

# include "push_swap.h"

/*-------------------------- DEFINE MACRO CONSTANTS --------------------------*/

enum e_greedy_sort_logic {
	RA_RB,
	RRA_RB,
	RA_RRB,
	RRA_RRB
};

/*--------------------------- STRUCT DECLARATIONS ----------------------------*/

typedef struct s_greedy_cost
{
	t_elem	*target;
	int		logic;
	int		total;
	int		cost_b;
	int		cost_a;
}	t_greedy_cost;

/*--------------------------- FUNCTION PROTOTYPES ----------------------------*/

int		compute_greedy_cost(t_ps_state *ps, t_elem *target, int logic);
void	complete_greedy_cost(t_ps_state *ps, t_elem *target, \
								int logic, t_greedy_cost *cost);

#endif