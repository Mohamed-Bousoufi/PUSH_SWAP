/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:09:31 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/09 20:19:38 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_push **lst)
{
	if ((*lst)->val > (*lst)->next->val
		&& (*lst)->next->val < (*lst)->next->next->val)
	{
		if ((*lst)->val < (*lst)->next->next->val)
			sa(lst);
		if ((*lst)->val > (*lst)->next->next->val)
			ra(lst);
	}
	else if ((*lst)->val > (*lst)->next->val
		&& (*lst)->next->val > (*lst)->next->next->val)
	{
		sa(lst);
		rra(lst);
	}
	else if ((*lst)->val < (*lst)->next->val
		&& (*lst)->next->val > (*lst)->next->next->val
		&& (*lst)->val > (*lst)->next->next->val)
		rra(lst);
	else if ((*lst)->val < (*lst)->next->val
		&& (*lst)->next->val > (*lst)->next->next->val
		&& (*lst)->val < (*lst)->next->next->val)
	{
		rra(lst);
		sa(lst);
	}
}

void	four_sort(t_push **a)
{
	t_push	*b;

	b = NULL;
	while ((*a)->index != 1)
		rra(a);
	pb(a, &b);
	three_sort(a);
	pa(a, &b);
}

void	five_sort(t_push **a, t_push **b)
{
	t_push	*tmp;
	int		i;

	i = 0;
	tmp = (*a);
	while (tmp->index != 1)
	{
		i++;
		tmp = tmp->next;
	}
	rotate(a, b, 1, i);
	i = 0;
	tmp = (*a);
	while (tmp->index != 2)
	{
		i++;
		tmp = tmp->next;
	}
	rotate(a, b, 2, i);
	three_sort(a);
	pa(a, b);
	pa(a, b);
}

void	rotate(t_push **a, t_push **b, int index, int nins)
{
	if (nins <= ft_lstsize(*a) / 2)
	{
		while ((*a)->index != index)
			ra(a);
		pb(a, b);
	}
	else if (nins > ft_lstsize(*a) / 2)
	{
		while ((*a)->index != index)
			rra(a);
		pb (a, b);
	}
}

int	check_sort(t_push *a)
{
	t_push	*tmp;

	tmp = a;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	if (a->index != 1)
		return (0);
	return (1);
}
