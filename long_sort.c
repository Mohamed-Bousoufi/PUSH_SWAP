/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:27:23 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/22 23:13:04 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int partition1(t_push **a, int start,int end)
{
	t_push *tmp;
	int j;
	int l;
	tmp = (*a);
	j = 0;
	l = -1;
	while (tmp)
	{
		if (tmp->index >= start && tmp->index <= end)
		{
			l = j;
		}
		tmp = tmp->next;
		j++;
	}
	return (l);
}
void dush(t_push **a, t_push **b, int end, int start, int i)
{
	int var = 0;
	if (i < (ft_lstsize(*a) / 2))
	{
		while (var < i)
		{
			ra(a);
			var++;
		}
	}
	if (i >= (ft_lstsize(*a) / 2))
	{
		while (var < (ft_lstsize(*a) - i))
		{
			rra(a);
			var++;
		}
	}
	if ((*a)->index >= (end+start) / 2)
	{
		pb(a, b);
	}
	else if ((*a)->index < (end+start) / 2)
	{
		pb(a, b);
		rb(b);
	}
}

int find_index(t_push **a, t_push **b, int start, int end)
{
	int i;
	int q;
	int size;

	i = 0;
	q = start;
	size = end;

		i = partition1(a,start,end);
		if (i == -1)
				return (1);
		dush(a, b, end, start, i);
	return (0);
}

void fast(t_push **a, t_push **b)
{
	int size = ft_lstsize(*a);
	int start = 1;
	int end = (size / 5);
	int i = 0;
	(void)b;
	while (start <= size)
	{
		while (i < size)
		{
			find_index(a, b, start, end);
			i++;
		}
		i = 0;
		start = end;
		end += (size / 5);
	}
}
void sort_stack_b(t_push **a, t_push **b)
{
	t_push *tmp;
	int max;
	int j;
	int i;
	(void)a;
	i = 0;
	j = 0;
	tmp = (*b);
	max = ft_lstsize(*b);
	while (max)
	{
		tmp = (*b);
		while (tmp)
		{
			if (tmp->index == max)
			{
				oush(a, b, j, max);
			}
			tmp = tmp->next;
			j++;
		}
		j = 0;
		max--;
	}
}

void oush(t_push **a, t_push **b, int j, int max)
{
	int size;
	int indx;
	(void)max;
	size = ft_lstsize(*b);
	indx = size - j;
	if (size - j <= size / 2)
	{
		while (indx)
		{
			rrb(b);
			indx--;
		}
	}
	else if (size - j > size / 2)
	{
		while (j)
		{
			rb(b);
			j--;
		}
	}
	pa(a, b);
}
