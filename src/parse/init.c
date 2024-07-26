/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:27:21 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/07/27 00:54:39 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

static void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
			}
			j++;
		}
		i++;
	}
}

static int	*sorted_array(const int *array, int size)
{
	int	*res;
	int	i;

	res = (int *)ft_calloc(size, sizeof(int));
	if (!res)
	{
		fprintf(stderr, "Error\n");
		exit(9);
	}
	i = 0;
	while (i < size)
	{
		res[i] = array[i];
		i++;
	}
	bubble_sort(res, size);
	return (res);
}

static void	order_array(int *not_ordered_array, int size)
{
	int	i;
	int	j;
	int	*ordered_array;

	i = 0;
	ordered_array = sorted_array(not_ordered_array, size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (not_ordered_array[i] == ordered_array[j])
			{
				not_ordered_array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static void	init_a(t_node **stack_a, int *aux, int size)
{
	int		i;
	int		*aux2;
	t_node	*node;

	i = 0;
	aux2 = aux_strcpy_int(aux, size);
	order_array(aux, size);
	while (i < size)
	{
		node = node_new(aux[i], aux2[i]);
		if (node)
			node_add_back(stack_a, node);
		i++;
	}
	free(aux2);
}

void	init(int *aux, int size, t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !stack_b)
	{
		fprintf(stderr, "Error\n");
		exit(8);
	}
	*stack_a = NULL;
	*stack_b = NULL;
	init_a(stack_a, aux, size);
}

/* void	ver_lista(t_node **start)
{
	int		i;
	t_node	*actual;
	t_node	*next_node;

	if (!start || !*start)
		return ;
	i = 0;
	actual = *start;
	while (actual)
	{
		printf("Node: %p, position: %d, content: %d\n",
			actual, actual->position, actual->content);
		next_node = actual->next;
		actual = next_node;
		i++;
	}
}
*/