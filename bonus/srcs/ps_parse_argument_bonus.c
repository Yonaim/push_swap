/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_argument_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:11:10 by yona              #+#    #+#             */
/*   Updated: 2022/11/10 18:15:22 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_numstr(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (FALSE);
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

static int	get_rank_of_elem(const t_elem *target, const t_deque *dq)
{
	int		rank;
	t_elem	*cmp;

	rank = 1;
	cmp = dq->p[TOP];
	while (cmp)
	{
		if (target->data > cmp->data)
			rank++;
		else if (target != cmp && target->data == cmp->data)
			exit_by_error("duplicated element exist");
		cmp = cmp->down;
	}
	return (rank);
}

static int	arg_atoi(const char *str)
{
	int	n;
	int	minus;

	minus = 0;
	if (is_numstr(str) == FALSE)
		exit_by_error("input argument not a number");
	if (*str == '+' || *str == '-')
		minus = (*str++ == '-');
	n = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (n > (INT_MAX / 10) || (n == (INT_MAX / 10) && (*str > '7' + minus)))
			exit_by_error("out of integer range");
		n = (n * 10) + (*str++ - '0');
	}
	if (minus == TRUE)
		n = n * (-1);
	return (n);
}

static void	arg_rank(t_deque *dq)
{
	int				*rank;
	unsigned int	i;
	t_elem			*cur;

	if (!dq)
		return ;
	rank = malloc(sizeof(int) * dq->count);
	cur = dq->p[TOP];
	i = 0;
	while (i < dq->count)
	{
		rank[i] = get_rank_of_elem(cur, dq);
		cur = cur->down;
		i++;
	}
	i = 0;
	cur = dq->p[TOP];
	while (i < dq->count)
	{
		cur->data = rank[i];
		cur = cur->down;
		i++;
	}
	free(rank);
}

void	ps_parse_argument(t_deque *dq, const int argc, const char *argv[])
{
	char	**split;
	t_elem	*new;
	int		i;
	int		j;

	ft_memset(dq, 0, sizeof(t_deque));
	i = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		if (!split[j])
			exit_by_error("empty string");
		while (split[j])
		{
			new = newelem(arg_atoi(split[j]));
			enqueue(dq, BOTTOM, new);
			free(split[j++]);
		}
		free(split);
	}
	if (dq->count == 0)
		exit(EXIT_FAILURE);
	arg_rank(dq);
}
