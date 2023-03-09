/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:56:23 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/09 22:36:52 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_push
{
	int				val;
	int				index;
	struct s_push	*next;

}t_push;

t_push		*ft_lstnew(int val);
t_push		*ft_lstlast(t_push *lst);
void		ft_lstadd_back(t_push **lst, t_push *new);
size_t		ft_strlen(const char *s);
long long	ft_atoi(const char *str);
void		ft_error(void);
void		check_arg(char *s);
void		sa(t_push **s);
void		ra(t_push **s);
void		rra(t_push **s);
void		pb(t_push **b, t_push **a);
void		three_sort(t_push **lst);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t count);
void		ft_duplicate(char **arg);
void		five_sort(t_push **a, t_push **b);
int			ft_lstsize(t_push *lst);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
void		check_arg(char *s);
int			check_taille(long n);
void		four_sort(t_push **a);
void		rotate(t_push **a, t_push **b, int size, int index);
void		make_list(char **argv, t_push **a);
void		short_sort(t_push **a, t_push **b);
int			check_sort(t_push *a);
void		pa(t_push **a, t_push **b);
void		sb(t_push **s);
void		rb(t_push **s);
void		rrb(t_push **s);
void		pusha_b(t_push **a, t_push **b);
void		sort_stack_b(t_push **a, t_push **b);
void		oush(t_push **b, int j);
void		min_ins(t_push **a, t_push **b, int start, int end);
int			get_it(t_push **a, int max);
void		initailize_list(t_push **lst);
int			maxval(t_push **a);
void		five_hundred(t_push **a, t_push **b);
int			count(t_push **a, int max);
#endif