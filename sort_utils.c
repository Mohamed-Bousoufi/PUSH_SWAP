/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:09:31 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/18 12:56:37 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_push **lst)
{
	if ((*lst)->val > (*lst)->next->val
		&& (*lst)->next->val < (*lst)->next->next->val)
	{
		if ((*lst)->val < (*lst)->next->next->val) /*2 1 3*/
			sa(lst);
		if ((*lst)->val > (*lst)->next->next->val) /*3 1 2*/
			ra(lst);
	}
	else if ((*lst)->val > (*lst)->next->val
		&& (*lst)->next->val > (*lst)->next->next->val) /*3 2 1*/
	{
		sa(lst);
		rra(lst);
	}
	else if ((*lst)->val < (*lst)->next->val
		&& (*lst)->next->val > (*lst)->next->next->val
		&& (*lst)->val > (*lst)->next->next->val) /*2 3 1*/
		rra(lst);
	else if ((*lst)->val < (*lst)->next->val
		&& (*lst)->next->val > (*lst)->next->next->val
		&& (*lst)->val < (*lst)->next->next->val) /*1 3 2*/
	{
		rra(lst);
		sa(lst);
	}
}

void	four_sort(t_push **a)
{
	t_push	*b;

	b = NULL;
	while ((*a)->index != 0)
		rra(a);
	pb(a, &b);
	three_sort(a);
	pa(a, &b);
	ra(a);
}

void	five_sort(t_push **a, t_push **b)
{
	t_push	*tmp;
	int		i;

	i = 0;
	tmp = (*a);
	while (tmp->index != 0)
	{
		i++;
		tmp = tmp->next;
	}
	rotate(a, b, 0, i);
	i = 0;
	tmp = (*a);
	while (tmp->index != 1)
	{
		i++;
		tmp = tmp->next;
	}
	rotate(a, b, 1, i);
	three_sort(a);
	pa(a, b);
	ra(a);
	pa(a, b);
	ra(a);
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
		if (tmp->index < tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	short_sort(t_push **a, t_push **b)
{
	if (check_sort(*a))
		exit(0);
	if (ft_lstsize(*a) == 2)
	{
		if ((*a)->index == 0)
			sa(a);
	}
	if (ft_lstsize(*a) == 3)
		three_sort(a);
	if (ft_lstsize(*a) == 4)
		four_sort(a);
	if (ft_lstsize(*a) == 5)
		five_sort(a, b);
}
