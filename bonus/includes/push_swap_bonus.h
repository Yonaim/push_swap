/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:32:06 by yeonhkim          #+#    #+#             */
/*   Updated: 2022/11/12 15:35:42 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

/*--------------------------- USER DEFINED HEADERS ---------------------------*/

# include "libft.h"
# include "common_bonus.h"
# include "deque_bonus.h"

/*-------------------------- DEFINE MACRO CONSTANTS --------------------------*/

# define DEBUG_MODE FALSE

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

/*--------------------------- STRUCT DECLARATIONS ----------------------------*/

typedef struct s_solution
{
	t_list			*cmds;
	unsigned int	cmdcnt;
}	t_solution;

typedef struct s_ps_state
{
	t_deque				*a;
	t_deque				*b;
	unsigned int		intcnt;
	t_solution			*soln;
	struct s_ps_state	*(*sa)(struct s_ps_state *ps);
	struct s_ps_state	*(*sb)(struct s_ps_state *ps);
	struct s_ps_state	*(*ss)(struct s_ps_state *ps);
	struct s_ps_state	*(*pa)(struct s_ps_state *ps);
	struct s_ps_state	*(*pb)(struct s_ps_state *ps);
	struct s_ps_state	*(*ra)(struct s_ps_state *ps);
	struct s_ps_state	*(*rb)(struct s_ps_state *ps);
	struct s_ps_state	*(*rr)(struct s_ps_state *ps);
	struct s_ps_state	*(*rra)(struct s_ps_state *ps);
	struct s_ps_state	*(*rrb)(struct s_ps_state *ps);
	struct s_ps_state	*(*rrr)(struct s_ps_state *ps);
}	t_ps_state;

/*---------------------------- TYPE DECLARATIONS -----------------------------*/

typedef void		(*t_ps_sort)(t_ps_state *ps);
typedef t_ps_state	*(*t_ps_instr)(t_ps_state *ps);

/*--------------------------- FUNCTION PROTOTYPES ----------------------------*/

/* program main logic */
void		ps_parse_argument(t_deque *dq, int argc, const char *argv[]);

/* push_swap instructions */
t_ps_state	*sa(t_ps_state *ps);
t_ps_state	*sb(t_ps_state *ps);
t_ps_state	*ss(t_ps_state *ps);
t_ps_state	*pa(t_ps_state *ps);
t_ps_state	*pb(t_ps_state *ps);
t_ps_state	*ra(t_ps_state *ps);
t_ps_state	*rb(t_ps_state *ps);
t_ps_state	*rr(t_ps_state *ps);
t_ps_state	*rra(t_ps_state *ps);
t_ps_state	*rrb(t_ps_state *ps);
t_ps_state	*rrr(t_ps_state *ps);

/* utils */
void		lstadd_new_back(t_list **lst, void *content);
void		exit_by_error(char *msg);

#endif
