/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:45:35 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/19 19:53:13 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

void order_stack(t_node **stackA, t_node **stackB)
{
    t_node  *current;
    int     size;

    if (is_ordered(stackA) != 0)
    {
        current = *stackA;
        size = node_size(current);
        if (size == 2 && current->content > current->next->content)
            sa(stackA);
        else if (size == 3)
            sort_three_elements(stackA);
        else if (size > 3 && size < 6)
            sort_five_elements(stackA, stackB);
        else
            sort_big_stack(stackA, stackB);
    }
}