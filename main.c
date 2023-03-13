/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:27:18 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/13 17:10:24 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_push **a, t_push **b)
{
	if (ft_lstsize(*a) == 2)
	{
		if ((*a)->index != 1)
			sa(a);
	}
	else if (ft_lstsize(*a) == 3)
		three_sort(a);
	else if (ft_lstsize(*a) == 4)
		four_sort(a);
	else if (ft_lstsize(*a) == 5)
		five_sort(a, b);
	else if ((ft_lstsize(*a) <= 100 && ft_lstsize(*a) > 5)
		|| ft_lstsize(*a) > 500)
	{
		pusha_b(a, b);
		sort_stack_b(a, b);
		exit(0);
	}
	else if (ft_lstsize(*a) == 500)
	{
		pusha_b(a, b);
		five_hundred(a, b);
		exit(0);
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

int	main(int argc, char **argv)
{
	t_push	*a;
	t_push	*b;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		make_list(argv, &a);
		dpl(&a);
		indx(&a);
		if (check_sort(a))
			exit(0);
		short_sort(&a, &b);
		free_stack(a);
	}
	else
		exit(0);
}
