/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:48:00 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/08 15:50:24 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

int	is_ordered(t_node **stack)
{
    t_node	*aux;

    if (!stack)
        return (1);

    aux = *stack;
    while (aux->next)
    {
        if (aux->content > aux->next->content)
            return (1);
        aux = aux->next;
    }
    return (0);
}

t_node  *find_highest(t_node **stack)
{
    t_node  *res;
    t_node  *actual;

    if (*stack == NULL) {
        return NULL;
    }

    actual = *stack;
    res = actual;
    
    while (actual)
    {
        if (actual->content > res->content)
            res = actual;
        actual = actual->next;
    }
    return(res);
}

void    sort_three_elements(t_node **stack)
{
    t_node  *highest;

    highest = find_highest(stack);
    if (*stack == highest)
        ra(stack);
    else if ((*stack)->next == highest)
        rra(stack);
    if ((*stack)->content > (*stack)->next->content)
        sa(stack);
}


void    sort_five_elements(t_node **stackA, t_node **stackB)
{
    int i;
    int size;
    t_node  *highest;

    i = 0;
    size = ft_lstsize(*stackA);
    while (i < size - 3)
    {
        highest = find_highest(stackA);
        if (*stackA == highest)
            ra(stackA);
        else if ((*stackA)->next == highest)
            rra(stackA);
        if ((*stackA)->content > (*stackA)->next->content)
            sa(stackA);
        pb(stackA, stackB);
        i++;
    }
    sort_three_elements(stackA);
    pa(stackA, stackB);
    pa(stackA, stackB);
}



/*
170 45 75 90 802 24 2 66

2 24 45 66 75 90 170 802
*/