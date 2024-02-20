/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:07 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/20 22:01:26 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

//SWAP
void	swap(t_stack	**stack)
{
    if (!*stack || !(*stack)->next)
        return ;

    *stack = (*stack)->next; //cabeza de la pila -> al siguiente nodo, 2do nodo = nueva cabeza de la pila.
    (*stack)->prev->prev = *stack; //puntero prev del nodo original (ahora el segundo nodo) -> al nuevo primer nodo (el que solía ser el segundo).
    (*stack)->prev->next = (*stack)->next; //actualiza el puntero next del nodo anterior al nuevo primer nodo para que apunte al siguiente nodo en la pila.

    if((*stack)->next) //verifica si hay un siguiente nodo después del nuevo primer nodo. Si es así, actualiza el puntero prev del siguiente nodo para que apunte al nodo anterior (que es ahora el primer nodo).
        (*stack)->next->prev = (*stack)->prev;
    (*stack)->next = (*stack)->prev; //establece el puntero next del nuevo primer nodo al nodo anterior (que ahora es el segundo nodo).
    (*stack)->prev = NULL; //establece el puntero prev del nuevo primer nodo a NULL ya que ahora es el primer elemento en la pila.

}


//sa


//sb


//ss

