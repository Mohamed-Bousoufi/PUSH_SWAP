/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:10:38 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/12 21:31:27 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	initailize_list(t_push **lst)
{
	t_push	*tmp;

	tmp = (*lst);
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
}

int	check_taille(long n)
{
	if (n < -2147483648 || n > 2147483647)
	{
		ft_error();
	}
	return ((int)n);
}
