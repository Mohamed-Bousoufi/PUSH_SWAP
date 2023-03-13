/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:57:17 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/12 20:56:44 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	make_list(char **argv, t_push **a)
{
	t_push	*t_push;
	char	**argz;
	char	**tmp;
	int		i;
	int		j;

	t_push = NULL;
	i = 1;
	while (argv[i])
	{
		j = -1;
		check_arg(argv[i]);
		argz = ft_split(argv[i], ' ');
		tmp = argz;
		while (argz[++j])
		{
			if (ft_strlen(argz[j]) > 11)
				ft_error();
			t_push = ft_lstnew(check_taille(ft_atoi(argz[j])));
			free(tmp[j]);
			ft_lstadd_back(a, t_push);
		}
		free(tmp);
		i++;
	}
}

void	dpl(t_push **a)
{
	t_push		*b;
	t_push		*c;

	b = (*a);
	while (b)
	{
		c = b;
		while (c->next)
		{
			if (b->val == c->next->val)
			{
				write(2, "Error\n", 7);
				exit(1);
			}
			c = c->next;
		}
		b = b->next;
	}
}

void	indx(t_push **lst)
{
	int		flag;
	t_push	*tmp;
	t_push	*max;
	int		i;

	flag = 1;
	initailize_list(lst);
	i = ft_lstsize(*lst);
	while (flag)
	{
		tmp = (*lst);
		max = NULL;
		flag = 0;
		while (tmp)
		{
			if (tmp->index == -1 && (max == NULL || tmp->val > max->val))
			{
				max = tmp;
				flag = 1;
			}
			tmp = tmp->next;
		}
		max && (max->index = i--);
	}
}

int	check_sort(t_push *a)
{
	t_push	*tmp;
	int		i;

	tmp = a;
	i = 0;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
		{
			return (0);
		}
		tmp = tmp->next;
		i++;
	}
	if (a->index != 1)
		return (0);
	return (1);
}

void	free_stack(t_push *a)
{
	t_push	*tmp;

	tmp = a;
	if (tmp)
	{
		while (tmp)
		{
			free(tmp);
			tmp = tmp->next;
		}
		free(tmp);
	}
}
