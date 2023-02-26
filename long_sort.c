/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:27:23 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/26 18:48:23 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void min_ins(t_push **a,t_push **b,int start,int end)
{
	if((*a) && (*a)->index <= end && (*a)->index >= start)
	{
		if((*a)->index <= (start +end)/2)
			pb(a,b);
		else
		{
			pb(a,b);
			rb(b);
		}
	}
	else
		ra(a);
}



int partition1(t_push **a, int start, int end)
{
	t_push	*tmp;
	int		j;
	int		l;

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
	int	var;

	var = 0;

	if (i <= (ft_lstsize(*a) / 2))
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
	if ((*a)->index > (end + start) / 2)
	{
		pb(a, b);
	}
	else if ((*a)->index <= (end + start) / 2)
	{
		pb(a, b);
		rb(b);
	}
}

int	find_index(t_push **a, t_push **b, int start, int end)
{
	int		i;

	i = 0;
	i = partition1(a, start, end);
	if (i == -1)
		return (1);
		dush(a, b, end, start,i);
	return (0);
}

void	fast(t_push **a, t_push **b)
{
	int		i;
	int		end;
	int		start;
	int		size;

	size = ft_lstsize(*a);
	start = 1;
	end = (size / 5);
	i = 1;
	while (start <= size)
	{
		while (i <= size)
		{
			min_ins(a,b,start,end);
			i++;
		}
		i = 0;
		start = end;
		end += (size / 5);
	}
}
int get_it(t_push **a,int max)
{
	int i = 0;
	t_push *tmp;
	tmp = (*a);
	while(tmp)
	{
		if(tmp->index == max)
		{
			return(i);
		}
		i++;
		tmp = tmp->next;
	}
	return(-1);
}
void sort_stack_b(t_push **a, t_push **b)
{
	(void)a;
	int size;
	int max;
	int i;
	i = 0;
	t_push *tmp;
	tmp = (*b);
	size = ft_lstsize(*b);
	max = ft_lstsize(*b);
	while(size)
	{
		if(tmp->index == max)
		{
			pa(a,b);
			tmp = (*b);
			max--;
		}
		 if(tmp->index == max - 1)
		{
			pa(a,b);
			tmp = (*b);
		}
		if(ft_lstlast(tmp)->index == max)
		{
			rrb(b);
			tmp = (*b);
			max--;
		}
		 if(ft_lstlast(tmp)->index == max - 1)
		{
			rrb(b);
			pa(a,b);
			tmp = (*b);
		}
		else
		{
			rb(b);
			tmp = (*b);
		}
		size--;
		// printf("%d\n",ft_lstlast(tmp)->val);
	}
}

void	oush(t_push **a, t_push **b, int j)
{
	int	size;
	int	indx;

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
