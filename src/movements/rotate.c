/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/28 11:39:04 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

//ROTATE
void    rotate(t_node **stack)
{
	t_node *node = *stack;

    if (!*stack || !(*stack)->next)
        return ;

	*stack = (*stack)->next;
	node_add_back(stack, node_new(node->content, node->position));
	free(node);
}

//ra
void    ra(t_node **a)
{
    rotate(a);
    printf("ra\n");
}

//rb
void    rb(t_node **b)
{
    rotate(b);
    printf("rb\n");
}

//rr
void    rr(t_node **a, t_node **b)
{
    rotate(a);
    rotate(b);
    printf("rr\n");
}
