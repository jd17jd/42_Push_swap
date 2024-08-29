/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_methods_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:17:17 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/08/29 18:40:51 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

int	calculate_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_by_bit(t_node **stack_a, t_node **stack_b, int bit, int size)
{
	int	j;
	int	num;

	j = 0;
	while (j < size)
	{
		num = (*stack_a)->position;
		if (((num >> bit) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		j++;
	}
}

void	move_elements_back_to_a(t_node **stack_a, t_node **stack_b)
{
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_big_stack(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	size;
	int	max_bits;

	i = 0;
	size = node_size(*stack_a);
	max_bits = calculate_max_bits(size - 1);
	while (i < max_bits)
	{
		sort_by_bit(stack_a, stack_b, i, size);
		move_elements_back_to_a(stack_a, stack_b);
		i++;
	}
}
