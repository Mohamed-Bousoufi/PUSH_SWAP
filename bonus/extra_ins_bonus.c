/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_ins_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:24:18 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/11 13:37:15 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

void	pb(t_push **a, t_push **b)
{
	t_push	*tmp;

	if ((*a) != NULL)
	{
			tmp = (*a);
			(*a) = (*a)->next;
			tmp->next = (*b);
			(*b) = tmp;
	}
}

void	pa(t_push **a, t_push **b)
{
	t_push	*tmp;

	if ((*b) != NULL)
	{
			tmp = (*b);
			(*b) = (*b)->next;
			tmp->next = (*a);
			(*a) = tmp;
	}
}

void	rrb(t_push **s)
{
	t_push	*tmp;
	t_push	*swp;

	if ((*s) != NULL && (*s)->next != NULL)
	{
		tmp = (*s);
		while (tmp->next != NULL)
		{
			swp = tmp;
			tmp = tmp->next;
		}
		tmp = ft_lstlast((*s));
		tmp->next = (*s);
		swp->next = NULL;
		(*s) = tmp;
	}
}
