/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:01 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/06 13:52:05 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

// REVERSE ROTATION

void	rev_rotate(t_node **stack)
{
    t_node *last;

    if (!*stack || !(*stack)->next)
        return ;

    last = *stack;
    while (last->next)
        last = last->next;

    if (last->prev)
        last->prev->next = NULL;

    // Move the last node to the top of the stack.
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
}
/* void    rev_rotate(t_node **stack)
{
    t_node *tmp;
    
    if (!*stack || !(*stack)->next)
        return ;
    
    tmp = node_last(*stack);
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    //node_delete(stack, tmp);
    
    node_add_front(stack, node_new(tmp->content, tmp->position));
    
    free(tmp);    
} */

//rra. Base a la cima (en stackA)
void	rra(t_node **a)
{
	rotate(a);
	printf("rra\n");
}

//rrb. Base a la cima (en stackB)
void	rrb(t_node **b)
{
    rotate(b);
    printf("rrb\n");
}

//rrr
void    rrr(t_node **a, t_node **b)
{
    rotate(a);
    rotate(b);
    printf("rrr\n");
}