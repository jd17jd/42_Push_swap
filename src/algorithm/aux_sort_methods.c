/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_sort_methods.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:01:24 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/05 12:04:31 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

t_node	*find_lowest(t_node **stack)
{
	t_node	*res;
	t_node	*current;

	if (*stack == NULL)
		return (NULL);
	current = *stack;
	res = current;
	while (current)
	{
		if (current->position < res->position)
			res = current;
		current = current->next;
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
