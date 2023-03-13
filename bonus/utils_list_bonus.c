/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:47:49 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/12 21:12:24 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_push	*ft_lstnew(int val)
{
	t_push	*new;

	new = (t_push *)malloc(sizeof(t_push *));
	if (!new)
		return (0);
	new->val = val;
	new->next = NULL;
	return (new);
}

t_push	*ft_lstlast(t_push *lst)
{
	t_push	*temp;

	temp = lst;
	if (!lst)
	{
		return (0);
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

void	ft_lstadd_back(t_push **lst, t_push *new)
{
	t_push	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t count)
{
	int	i;

	i = -1;
	while (++i < (int)count && (s1[i] || s2[i]))
	{
		if (s2[i] != s1[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

int	ft_lstsize(t_push *lst)
{
	int		i;
	t_push	*rest;

	i = 0;
	rest = lst;
	while (lst != NULL)
	{
		i++;
		lst = lst -> next;
	}
	lst = rest;
	return (i);
}
