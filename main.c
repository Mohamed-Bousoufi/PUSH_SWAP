/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:27:18 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/22 23:17:11 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_push *prev, t_push *nxt)
{
	int	tmp;

	tmp = prev->val;
	prev->val = nxt->val;
	nxt->val = tmp;
}

void	indx (t_push **lst)
{
	int		flag;
	t_push	*tmp;
	t_push	*max;
	int		i;

	flag = 1;
	tmp = (*lst);
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
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
void dpl(t_push **a)
{
	t_push *b;
	t_push *c;

	b = (*a);
	while (b)
	{
		c = b;
		while (c->next)
		{
			if (b->val == c->next->val)
			{
				puts("error");
				exit(1);
			}
			c = c->next;
		}
		b = b->next;
	}
}

void make_list(char **argv, t_push **a)
{
	t_push *t_push;
	char **argz;
	char **tmp;
	int i;
	int j;

	t_push = NULL;
	i = 1;
	while (argv[i])
	{
		j = 0;
		check_arg(argv[i]);
		argz = ft_split(argv[i], ' ');
		tmp = argz;
		while (argz[j])
		{
			t_push = ft_lstnew(check_taille(ft_atoi(argz[j])));
			free(tmp[j]);
			ft_lstadd_back(a, t_push);
			j++;
		}
		free(tmp);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_push *a;
	t_push *b;

	int		i;
	i = 0;

	(void)argc;
	a = NULL;
	b = NULL;
	make_list(argv, &a);
	dpl(&a);
	indx(&a);
	fast(&a,&b);
	sort_stack_b(&a,&b);
	// while (b != NULL)
	// {
	// 	printf("%d||-->>||%d\n",b->val, b->index);
	// 	b = b->next;
	// }
	while (a != NULL)
	{
		printf("%d||-->>||%d\n",a->val, a->index);
		a = a->next;
	}
}
