/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:05:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/08/29 18:59:35 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

#include "../../inc/ft_push_swap.h"

void	ver_lista(t_node **start)
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

void	pruebas_movements(t_node **stackA, t_node **stackB)
{
	printf("PRUEBA 1\n");
	printf("Stack A\n");
	ver_lista(stackA);

	printf("Stack B\n");
	ver_lista(stackB);
	printf("\n");


	printf("PRUEBA 2\n");
	sa(stackA);
	printf("Stack A\n");
	ver_lista(stackA);

	printf("Stack B\n");
	ver_lista(stackB);
	printf("\n");


	printf("PRUEBA 3\n");
	ra(stackA);
	printf("Stack A\n");
	ver_lista(stackA);

	printf("Stack B\n");
	ver_lista(stackB);
	printf("\n");


	printf("PRUEBA 4\n");
	rra(stackA);
	printf("Stack A\n");
	ver_lista(stackA);

	printf("Stack B\n");
	ver_lista(stackB);
	printf("\n");


	printf("PRUEBA 5\n");
	pa(stackA, stackB);
	printf("Stack A\n");
	ver_lista(stackA);

	printf("Stack B\n");
	ver_lista(stackB);
	printf("\n");
}


void	pruebas_algorithm(t_node **stackA, t_node **stackB)
{
	printf("PRUEBA FUNCTION is_ordered()\n");
	printf("Stack A: %d\n", is_ordered(stackA));
	printf("Stack B: %d\n", is_ordered(stackB));

	printf("	PRUEBAS SORT METHODS\n");
	printf("	Lista no ordenada\n");
	printf("STACK A:\n");
	ver_lista(stackA);
	printf("\n");
	printf("STACK B:\n");
	ver_lista(stackB);
	printf("\n");

	printf("	Movimientos:\n");
	//sort_three_elements(stackA);
	//sort_five_elements(stackA, stackB);
	sort_big_stack(stackA, stackB);
	printf("\n");
	
	printf("	Lista ordenada\n");
	printf("STACK A:\n");
	ver_lista(stackA);
	printf("\n");
	printf("STACK B:\n");
	ver_lista(stackB);
	printf("\n");
}
*/
