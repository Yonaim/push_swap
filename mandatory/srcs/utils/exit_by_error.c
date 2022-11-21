/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_by_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:11:28 by yona              #+#    #+#             */
/*   Updated: 2022/11/12 15:02:29 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_by_error(char *msg)
{
	if (DEBUG_MODE == TRUE)
	{
		ft_putstr_fd("ERROR : ", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
	}
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
