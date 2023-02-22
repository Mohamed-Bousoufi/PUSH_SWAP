/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:56:23 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/22 23:13:30 by mbousouf         ###   ########.fr       */
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

typedef struct s_mem
{
	char			**mem;
	struct s_mem	*next;
}t_mem;

t_push		*ft_lstnew(int val);
t_push		*ft_lstlast(t_push *lst);
void		ft_lstadd_back(t_push **lst, t_push *new);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
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
void		ft_error(void);
void		check_arg(char *s);
void		two_face(char **v, char **arg);
void		ft_duplicate(char **arg);
int			check_taille(long long n);
void		four_sort(t_push **a);
void		rotate(t_push **a, t_push **b, int size, int index);
void		make_list(char **argv, t_push **a);
void		short_sort(t_push **a, t_push **b);
int			check_sort(t_push *a);
void		*my_malloc(int size, t_mem **mem);
void		pa(t_push **a, t_push **b);
void		sb(t_push **s);
void		rb(t_push **s);
void		rrb(t_push **s);
int	find_index(t_push **a, t_push **b, int start, int end);
void	fast(t_push **a, t_push **b);
void sort_stack_b(t_push **a, t_push **b);
void oush(t_push **a, t_push **b, int j, int max);
int partition1(t_push **a, int start,int end);
#endif