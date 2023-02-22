/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:21:34 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/17 21:55:49 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mem	*ft_memlast(t_mem *lst)
{
	t_mem	*temp;

	temp = lst;
	if (lst == NULL)
		return (0);
	else
	{
		while (temp)
			temp = temp->next;
	}
	return (temp);
}

void	mem_add_back(t_mem **lst, t_mem *new)
{
	t_mem	*last;

	if (lst != NULL)
	{
		last = ft_memlast(*lst);
		last->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
	}
}

void	*my_malloc(int size, t_mem **mem)
{
	void	*ptr;
	t_mem	*new;

	new = malloc(sizeof(t_mem));
	ptr = malloc(size);
	new->mem = ptr;
	mem_add_back(mem, new);
	puts("after");
	return (ptr);
}