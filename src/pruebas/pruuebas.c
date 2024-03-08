/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruuebas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:05:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/08 14:53:26 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

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
	printf("PPRUEBA FUNCTION is_ordered()\n");
	printf("%d\n", is_ordered(stackA));
	printf("%d\n", is_ordered(stackB));
	printf("PPRUEBA FUNCTION sort_3_elements()\n");
	printf("	Lista no ordenada\n");
	ver_lista(stackA);
	//sort_3_elements(stackA);
	sort_three_elements(stackA);
	printf("	Lista ordenada\n");
	ver_lista(stackA);
	printf("PPRUEBA FUNCTION find_highest()\n");
	t_node	*aux;
	aux = find_highest(stackA);
	printf("%d\n", aux->content);

	
}
