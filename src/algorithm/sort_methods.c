/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:48:00 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/21 14:45:34 by jvivas-g         ###   ########.fr       */
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

static t_node	*find_highest(t_node **stack)
{
	t_node	*res;
	t_node	*current;

	if (!*stack)
		return (NULL);
	current = *stack;
	res = current;
	while (current)
	{
		if (current->position > res->position)
			res = current;
		current = current->next;
	}
	return (res);
}

static t_node	*find_lowest(t_node **stack)
{
	t_node	*res;
	t_node	*actual;

	if (*stack == NULL)
		return (NULL);
	actual = *stack;
	res = actual;
	while (actual)
	{
		if (actual->position < res->position)
			res = actual;
		actual = actual->next;
	}
	return (res);
}

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

static int	get_distance(t_node **stack, t_node *highest)
{
	int		i;
	t_node	*current;

	i = 0;
	current = *stack;
	while (current != highest)
	{
		i++;
		current = current->next;
	}
	return (i);
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
