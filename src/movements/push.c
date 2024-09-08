/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:57:57 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/08 22:18:17 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

/* PUSH */
void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux;

	if (!*stack_a)
		return ;
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	aux->prev = NULL;
	if (!*stack_b)
	{
		*stack_b = aux;
		aux->next = NULL;
	}
	else
	{
		aux->next = *stack_b;
		aux->next->prev = aux;
		*stack_b = aux;
	}
	*stack_b = aux;
}

/* pa. Cima de StackB a la cima de StackA */
void	pa(t_node **a, t_node **b)
{
	push(b, a);
	ft_printf("pa\n");
}

/* pb. Cima de StackA a la cima de StackB */
void	pb(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pb\n");
}
