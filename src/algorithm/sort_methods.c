/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:48:00 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/07/27 01:19:08 by jvivas-g         ###   ########.fr       */
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

void	sort_five_elements(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		size;
	t_node	*lowest;
	t_node	*current;

	i = 0;
	size = node_size(*stack_a);
	while (i < size - 3)
	{
		lowest = find_lowest(stack_a);
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
		pb(stack_a, stack_b);
		i++;
	}
	sort_three_elements(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_big_stack(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;
	int		num;

	i = 0;
	size = node_size(stack_a[0]);
	i = size - 1;
	max_bits = 0;
	while ((i >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = (*stack_a)->position;
			if (((num >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_b[0])
			pa(stack_a, stack_b);
		i++;
	}
}
