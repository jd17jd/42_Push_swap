/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:48:00 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/03 20:50:58 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	sort_three_elements(t_node **stack)
{
	t_node	*highest;

	highest = find_highest(stack);
	if (*stack == highest)
		ra(stack);
	else if ((*stack)->next == highest)
		rra(stack);
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
}

void	move_to_top(t_node **stack_a, t_node *lowest, int size)
{
	t_node	*current;

	current = *stack_a;
	if (get_distance(stack_a, lowest) < size / 2)
	{
		while (current != lowest)
		{
			ra(stack_a);
			current = *stack_a;
		}
	}
	else
	{
		while (current != lowest)
		{
			rra(stack_a);
			current = *stack_a;
		}
	}
}

void	push_lowest_to_b(t_node **stack_a, t_node **stack_b, int size)
{
	int		i;
	t_node	*lowest;

	i = 0;
	while (i < size - 3)
	{
		lowest = find_lowest(stack_a);
		move_to_top(stack_a, lowest, size);
		pb(stack_a, stack_b);
		i++;
	}
}

void	sort_five_elements(t_node **stack_a, t_node **stack_b)
{
	int		size;

	size = node_size(*stack_a);
	push_lowest_to_b(stack_a, stack_b, size);
	sort_three_elements(stack_a);
	move_elements_back_to_a(stack_a, stack_b);
}
