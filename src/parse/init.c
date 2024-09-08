/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:27:21 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/04 12:55:19 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

/* Ordena el array de menor a mayor */
static int	*bubble_sort(int *array, int size)
{
	int	*res;
	int	i;
	int	j;
	int	aux;

	res = aux_strcpy_int(array, size);
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (res[j] > res[j + 1])
			{
				aux = res[j];
				res[j] = res[j + 1];
				res[j + 1] = aux;
			}
			j++;
		}
		i++;
	}
	return (res);
}

/* Da el nuevo array con todo valores positivos */
static void	to_position_array(int *content_array, int size)
{
	int	i;
	int	j;
	int	*position_array;

	i = 0;
	position_array = bubble_sort(content_array, size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (content_array[i] == position_array[j])
			{
				content_array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(position_array);
}

/* Inicializa la pila A añadiendo nodo a nodo la info
correspondiente de position y content */
static void	init_a(t_node **stack_a, int *aux, int size)
{
	int		i;
	int		*content_array;
	t_node	*node;

	i = 0;
	content_array = aux_strcpy_int(aux, size);
	to_position_array(aux, size);
	while (i < size)
	{
		node = node_new(aux[i], content_array[i]);
		if (node)
			node_add_back(stack_a, node);
		i++;
	}
	free(content_array);
}

/* Inicializa las pilas (A con la info y B a null) */
void	init(int *aux, int size, t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !stack_b)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(7);
	}
	*stack_a = NULL;
	*stack_b = NULL;
	init_a(stack_a, aux, size);
}
