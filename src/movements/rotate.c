/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/07 00:29:10 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

//ROTATE
/* void    rotate(t_node **stack)
{
	t_node *tmp;

    if (!*stack || !(*stack)->next)
        return ;
        
    tmp = *stack;
	*stack = (*stack)->next;
    (*stack)->prev = NULL;
    //node_delete(stack, tmp);
    
	node_add_back(stack, node_new(tmp->content, tmp->position));
	
    free(tmp);
} */
void    rotate(t_node **stack)
{
    t_node *tmp;
    t_node *last;

    if (!*stack || !(*stack)->next)
        return ;

    tmp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;

    last = *stack;
    while (last->next)
        last = last->next;
    last->next = tmp;
    tmp->prev = last;
    tmp->next = NULL;
}

//ra. Cima a la base (en stackA)
void    ra(t_node **a)
{
    rotate(a);
    printf("ra\n");
}

//rb. Cima a la base (en stackA)
void    rb(t_node **b)
{
    rotate(b);
    printf("rb\n");
}

//rr. Ejecutar ra y rb al mismo tiempo
void    rr(t_node **a, t_node **b)
{
    rotate(a);
    rotate(b);
    printf("rr\n");
}
