/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:07 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/08 03:46:06 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

//SWAP
void    swap(t_node **stack)
{
    t_node *tmp;

    if (!*stack || !(*stack)->next)
        return ;
        
    tmp = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
        
    if (tmp->next)
        tmp->next->prev = tmp;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
}

//sa. Rotar los 2 nºs de la cima (en stackA)
void    sa(t_node **a)
{
    swap(a);
    printf("sa\n");
}

//sb. Rotar los 2 nºs de la cima (en stackB)
void    sb(t_node **b)
{
    swap(b);
    printf("sb\n");
}

//ss. Ejecutar sa y sb al mismo tiempo
void    ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
    printf("ss\n");
}
