/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:46:00 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/12 21:11:34 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	extra_ins(char *s, t_push **a, t_push **b)
{
	if (!ft_strncmp(s, "rrr\n", 4))
	{
		rra(a);
		rrb(a);
	}
	else if (!ft_strncmp(s, "pb\n", 3))
		pb(a, b);
	else if (!ft_strncmp(s, "pa\n", 3))
		pa(a, b);
	else
		ft_error();
}

void	inst(char *s, t_push **a, t_push **b)
{
	if (!ft_strncmp(s, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(s, "sb\n", 3))
		sb(a);
	else if (!ft_strncmp(s, "ss\n", 3))
	{
		sa(a);
		sb(b);
	}
	else if (!ft_strncmp(s, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(s, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(s, "rr\n", 3))
	{
		ra(a);
		rb(a);
	}
	else if (!ft_strncmp(s, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(s, "rrb\n", 4))
		rrb(b);
	else
		extra_ins(s, a, b);
}

void	read_ins(t_push **a, t_push **b)
{
	char	*s;
	char	*tmp;

	s = get_next_line(0);
	while (s != NULL)
	{
		tmp = s;
		inst(s, a, b);
		free(tmp);
		s = get_next_line(0);
	}
}

void	check_in(t_push **a, t_push **b)
{
	if (check_sort(*a) && !(*b))
	{
		free_stack(*a);
		free_stack(*b);
		write (1, "OK\n", 3);
	}
	else
	{
		free_stack(*a);
		free_stack(*b);
		write (1, "KO\n", 3);
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
		read_ins(&a, &b);
		check_in(&a, &b);
	}
}
