/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_methods_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:01:24 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/07/27 01:03:39 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

t_node	*find_lowest(t_node **stack)
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

t_node	*find_highest(t_node **stack)
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

int	get_distance(t_node **stack, t_node *highest)
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
