/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:40:51 by yonshin           #+#    #+#             */
/*   Updated: 2022/11/11 00:26:04 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	init_ps_state_for_checker(t_ps_state *ps, t_deque *argdq)
{
	ps->a = argdq;
	ps->b = ft_calloc(1, sizeof(t_deque));
	if (!ps->b)
		exit_by_error("malloc failure");
	ps->intcnt = ps->a->count;
	ps->sa = sa;
	ps->sb = sb;
	ps->ss = ss;
	ps->pa = pa;
	ps->pb = pb;
	ps->ra = ra;
	ps->rb = rb;
	ps->rr = rr;
	ps->rra = rra;
	ps->rrb = rrb;
	ps->rrr = rrr;
}

static int	get_instruction_idx(const char *str)
{
	static const char	*cmdstr[] = {
		SA, SB, SS,
		PA, PB,
		RA, RB, RR,
		RRA, RRB, RRR,
		NULL
	};
	int					idx;

	if (*str == '\n')
		return (FAILURE);
	idx = 0;
	while (cmdstr[idx])
	{
		if (ft_strncmp(cmdstr[idx], str, ft_strlen(str) - 1) == 0)
			return (idx);
		idx++;
	}
	return (FAILURE);
}

static void	checker_run(t_ps_state *ps)
{
	char				*cmd;
	const t_ps_instr	cmdf[] = {
		sa, sb, ss,
		pa, pb, ra,
		rb, rr,
		rra, rrb, rrr
	};

	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		if (get_instruction_idx(cmd) == FAILURE)
			exit_by_error("invalid instruction");
		cmdf[get_instruction_idx(cmd)](ps);
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char *argv[])
{
	t_ps_state	ps;
	t_deque		argdq;

	if (argc == 1)
		exit(EXIT_FAILURE);
	ps_parse_argument(&argdq, argc, (const char **)argv);
	init_ps_state_for_checker(&ps, &argdq);
	checker_run(&ps);
	if (is_sorted_state(ps.a, ps.intcnt) == TRUE)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	return (0);
}
