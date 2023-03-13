/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:46:36 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/13 16:01:01 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
void		make_list(char **argv, t_push **a);
void		dpl(t_push **a);
void		indx(t_push **lst);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t count);
int			ft_lstsize(t_push *lst);
void		initailize_list(t_push **lst);
int			check_taille(long n);
int			check_sort(t_push *a);
char		*get_next_line(int fd);
void		sa(t_push **s);
void		ra(t_push **s);
void		rb(t_push **s);
void		sb(t_push **s);
void		rra(t_push **s);
void		pb(t_push **a, t_push **b);
void		pa(t_push **a, t_push **b);
void		rrb(t_push **s);
void		free_stack(t_push *a);
#endif