/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:05:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/21 14:56:18 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int	main(int argc, char *argv[])
{
	int		*aux;
	int		size_int_list;
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc < 2)
	{
		fprintf(stderr, "Error\n");
		return (1);
	}
	aux = NULL;
	size_int_list = number_arguments(argc, argv);
	stack_a = (t_node **)ft_calloc(1, sizeof(t_node *));
	stack_b = (t_node **)ft_calloc(1, sizeof(t_node *));
	aux = parse(argc, argv);
	init(aux, size_int_list, stack_a, stack_b);
	order_stack(stack_a, stack_b);
	free(aux);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
