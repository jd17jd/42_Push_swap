/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:07 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/26 20:05:53 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

//SWAP
void	swap(t_node **stack)
{
    // verificacion nodos anteriores

    if (!*stack || !(*stack)->next)
        return ;

    // 1 - 2 - 3 - 4 - ...

    *stack = (*stack)->next; //puntero cabeza de pila = puntero al siguiente nodo
    // *stack = *2* - 3 - 4 - ...

    (*stack)->prev->prev = *stack;
    // puntero prev de 1 = puntero de la cabeza de pila (=2)
    // 2 <- 1

    (*stack)->prev->next = (*stack)->next;
    // puntero next de 1 = puntero next de la cabeza de pila (=3)
    // 1 -> 3

    // 2 <- 1 -> 3

    // verificacion nodos posteriores

    if((*stack)->next) 
        (*stack)->next->prev = (*stack)->prev;
    // puntero prev de 3 = puntero previo de la cabeza de la pila (=1)
    // 1 <- 3

    (*stack)->next = (*stack)->prev;
    // puntero next de 2 = puntero previo de la cabeza de la pila (=1)
    // 2 -> 1

    (*stack)->prev = NULL;
    // puntero previo de 2 = NUll
    // null <- 2

    // NULL <- 2 <-> 1 <-> 3
}


//sa
void    sa(t_node **a)
{
    swap(a);
    printf("sa\n");
}

//sb
void    sb(t_node **b)
{
    swap(b);
    printf("sb\n");
}

//ss
void    ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
    printf("ss\n");
}
