/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:53:07 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/07 16:25:46 by mbousouf         ###   ########.fr       */
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
