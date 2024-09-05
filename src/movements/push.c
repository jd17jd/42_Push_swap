/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:57:57 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/05 12:08:46 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

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

/* pa. Top of StackB to top of StackA */
void	pa(t_node **a, t_node **b)
{
	push(b, a);
	printf("pa\n");
}

/* pb. Top of StackA to top of StackB */
void	pb(t_node **a, t_node **b)
{
	push(a, b);
	printf("pb\n");
}
