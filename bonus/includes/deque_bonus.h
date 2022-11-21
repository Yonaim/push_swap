/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:45:10 by yona              #+#    #+#             */
/*   Updated: 2022/11/12 15:34:46 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_BONUS_H
# define DEQUE_BONUS_H

/*--------------------------- USER DEFINED HEADERS ---------------------------*/

# include "libft.h"
# include "common_bonus.h"

/*-------------------------- DEFINE MACRO CONSTANTS --------------------------*/

enum e_deque_edge {
	TOP,
	BOTTOM
};

/*--------------------------- STRUCT DECLARATIONS ----------------------------*/

typedef struct s_elem
{
	int				data;
	struct s_elem	*up;
	struct s_elem	*down;
}	t_elem;

typedef struct s_deque
{
	unsigned int	count;
	t_elem			*p[2];
}	t_deque;

/*--------------------------- FUNCTION PROTOTYPES ----------------------------*/

/* element put & out */
t_elem		*newelem(int data);
void		enqueue(t_deque *dq, int edge, t_elem *putelem);
t_elem		*dequeue(t_deque *dq, int edge);

/* deque object */
t_deque		*clone_deque(const t_deque *ori);
void		destroy_deque(t_deque *dq);

/* get info */
int			data(const t_deque *dq, int edge, int ordinal);
int			distance(const t_deque *dq, int edge, int find);
int			closest_edge(const t_deque *dq, int find);
int			is_sorted_state(const t_deque *a, const unsigned int intcnt);

#endif
