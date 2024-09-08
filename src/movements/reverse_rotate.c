/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:01 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/08 22:18:26 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

/* REVERSE ROTATION */
void	rev_rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

/* rra. Base a la cima (en stackA) */
void	rra(t_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

/* rrb. Base a la cima (en stackB) */
void	rrb(t_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

/* rrr */
void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
