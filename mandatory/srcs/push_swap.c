/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:20:13 by yona              #+#    #+#             */
/*   Updated: 2022/11/11 00:24:16 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list			*solutions;
	t_deque			argdq;

	if (argc < 2)
		exit(EXIT_FAILURE);
	ps_parse_argument(&argdq, argc, (const char **)argv);
	if (is_sorted_state(&argdq, argdq.count) == TRUE)
		exit(EXIT_SUCCESS);
	ps_solve(&solutions, &argdq);
	ps_print_best_solution(solutions);
	return (0);
}
