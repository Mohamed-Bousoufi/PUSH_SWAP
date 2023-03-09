/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:39:27 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/09 16:11:37 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	steps(t_push **a, t_push **b, int j)
{
	int		size;
	int		indx;

	size = ft_lstsize(*b);
	indx = size - j;
	if (j >= 0)
	{
		if (j <= size / 2)
		{
			while (j > 0)
			{
				rb(b);
				j--;
			}
		}
		else if (j > size / 2)
		{
			while (indx > 0)
			{
				rrb(b);
				indx--;
			}
		}
		pa(a, b);
	}
}

void	five_hundred(t_push **a, t_push **b)
{
	int		max;
	t_push	*tmp;
	int		i;
	int		j;

	tmp = (*b);
	max = maxval(b);
	while (max > 0)
	{
		i = get_it(b, max);
		j = get_it(b, max - 1);
		if (abs(j - ft_lstsize(*b) / 2) > abs(i - ft_lstsize(*b) / 2))
		{
			steps(a, b, count(b, max - 1));
			steps(a, b, count(b, max));
			sa(a);
		}
		else
		{
			steps(a, b, count(b, max));
			steps(a, b, count(b, max - 1));
		}
		max = maxval(b);
	}
}

int	count(t_push **a, int max)
{
	t_push	*tmp;
	int		i;

	i = 0;
	tmp = (*a);
	while (tmp)
	{
		if (tmp->index == max)
		{
			return (i);
		}
		i++;
		tmp = tmp->next;
	}
	return (-1);
}
