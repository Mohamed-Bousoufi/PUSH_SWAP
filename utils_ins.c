/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:53:07 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/23 12:57:43 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push **s)
{	
	t_push	*temp;

	if ((*s) != NULL && (*s)->next != NULL)
	{
		temp = (*s);
		(*s) = (*s)->next;
		temp->next = (*s)->next;
		(*s)->next = temp;
		puts("sa");
	}
}

void	sb(t_push **s)
{	
	t_push	*temp;

	if ((*s) != NULL && (*s)->next != NULL)
	{
		temp = (*s);
		(*s) = (*s)->next;
		temp->next = (*s)->next;
		(*s)->next = temp;
		puts("sb");
	}
}

void	ra(t_push **s)
{
	t_push	*temp;
	t_push	*swp;

	if ((*s) != NULL && (*s)->next != NULL)
	{
		temp = ft_lstlast(*s);
		temp->next = (*s);
		swp = (*s);
		(*s) = (*s)->next;
		swp->next = NULL;
		puts("ra");
	}
}

void	rb(t_push **s)
{
	t_push	*temp;
	t_push	*swp;

	if ((*s) != NULL && (*s)->next != NULL)
	{
		temp = ft_lstlast(*s);
		temp->next = (*s);
		swp = (*s);
		(*s) = (*s)->next;
		swp->next = NULL;
		puts("rb");
	}
}

void	rra(t_push **s)
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
		puts("rra");
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
		puts("rrb");
	}
}

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
	puts("pb");
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
	puts("pa");
}
