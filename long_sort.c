/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:27:23 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/13 14:25:28 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_ins(t_push **a, t_push **b, int start, int end)
{
	if ((*a) && (*a)->index <= end && (*a)->index >= start)
	{
		if ((*a)->index <= (start + end) / 2)
			pb(a, b);
		else
		{
			pb(a, b);
			rb(b);
		}
	}
	else
		ra(a);
}

void	pusha_b(t_push **a, t_push **b)
{
	int	end;
	int	start;
	int	size;
	int	inc;

	start = 0;
	end = 0;
	size = ft_lstsize(*a);
	if (size > 100)
		inc = size / 9;
	else
		inc = size / 4;
	while (start < size)
	{
		while (ft_lstsize(*b) < end)
			min_ins(a, b, start, end);
			start = end;
		if (end + inc >= size)
			end = size;
		else
			end = end + inc;
	}
}

void	sort_half(t_push **a, t_push **b, int max)
{
	t_push	*tmp;
	int		x;

	tmp = (*b);
	x = 0;
	if (tmp && tmp->index == max - 1)
	{
		pa(a, b);
		x = 1;
	}
	else if (tmp && ft_lstlast(tmp)->index == max - 1)
	{
		rrb(b);
		pa(a, b);
		x = 1;
	}
	oush(b, get_it(b, max));
	if ((*a) && (x == 1))
	{
		pa(a, b);
		sa(a);
	}
	else
		pa(a, b);
}

void	sort_stack_b(t_push **a, t_push **b)
{
	int		max;
	t_push	*tmp;

	tmp = (*b);
	while (ft_lstsize(*b) > 0)
	{
		max = maxval(b);
		if (tmp && tmp->index == max)
		{
			pa(a, b);
			tmp = (*b);
		}
		else if (tmp && ft_lstlast(tmp)->index == max)
		{
			rrb(b);
			pa(a, b);
			tmp = (*b);
		}
		else
		{
			sort_half(a, b, max);
			tmp = (*b);
		}
	}
}

void	oush(t_push **b, int j)
{
	int	size;
	int	indx;

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
	}
}
