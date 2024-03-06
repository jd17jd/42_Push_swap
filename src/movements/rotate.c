/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/06 13:51:49 by jvivas-g         ###   ########.fr       */
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
