/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:45:35 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/07/27 01:03:09 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

int	is_ordered(t_node **stack)
{
	t_node	*aux;

	if (!stack || !*stack)
		return (1);
	aux = *stack;
	while (aux->next)
	{
		if (aux->content > aux->next->content)
			return (1);
		aux = aux->next;
	}
	return (0);
}

void	order_stack(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	int		size;

	if (is_ordered(stack_a) != 0)
	{
		current = *stack_a;
		size = node_size(current);
		if (size == 2 && current->content > current->next->content)
			sa(stack_a);
		else if (size == 3)
			sort_three_elements(stack_a);
		else if (size > 3 && size < 6)
			sort_five_elements(stack_a, stack_b);
		else
			sort_big_stack(stack_a, stack_b);
	}
}
