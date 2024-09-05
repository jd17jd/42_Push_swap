/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:07 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/05 12:15:33 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	swap(t_node **stack)
{
	t_node	*tmp;

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

/* Rotate the top 2 elements of the StackA */
void	sa(t_node **a)
{
	swap(a);
	printf("sa\n");
}

/* Rotate the top 2 elements of the StackB */
void	sb(t_node **b)
{
	swap(b);
	printf("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}
