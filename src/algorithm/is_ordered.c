/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:48:00 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/08 03:49:03 by jvivas-g         ###   ########.fr       */
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

void    sort_3_elements(t_node **stack)
{
    int a;
    int b;
    int c;

    a = (*stack)->content;
    b = (*stack)->next->content;
    c = (*stack)->next->next->content;
    if (a > b && b < c && a < c)
        sa(stack);
    else if (a > b && b > c && a > c)
    {
        sa(stack);
        rra(stack);
    }
    else if (a > b && b > c && a < c)
        ra(stack);
    else if (a < b && b > c && a > c)
    {
        sa(stack);
        ra(stack);
    }
    else if (a < b && b > c && a < c)
        rra(stack);
}



/*
170 45 75 90 802 24 2 66

2 24 45 66 75 90 170 802
*/