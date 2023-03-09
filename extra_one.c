/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:18:32 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/09 20:41:43 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	maxval(t_push **a)
{
	t_push	*tmp;
	int		max;

	max = 0;
	if (*a)
	{
		tmp = (*a);
		max = tmp->index;
		while (tmp)
		{
			if (tmp->index > max)
			{
				max = tmp->index;
			}
			tmp = tmp->next;
		}
	}
	return (max);
}

int	get_it(t_push **a, int max)
{
	int		i;
	t_push	*tmp;

	tmp = (*a);
	i = 0;
	while (tmp)
	{
		if (tmp->index == max)
		{
			return (i);
		}
		tmp = tmp->next;
		i++;
	}
	return (-1);
}
