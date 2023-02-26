/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:38:15 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/25 12:21:55 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sperate(t_push *a)
{
    t_push *c;
    t_push *b;
    b = NULL;
    c = NULL;
    if(ft_lstsize(b) == 1 && ft_lstsize(c) == 1)
    {
        if(b->index < c->index)
            pb(&b,&c);
        else
        {
            pb(&b,&c);
            rb(&b);
        }
    }
    else
    {
        pb(&a,&b);
        pb(&a,&c);
        sperate(a);
    }
        
}

