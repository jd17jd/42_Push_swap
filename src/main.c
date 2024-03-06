/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:05:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/06 13:51:28 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/ft_push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	**stackA;
	t_node	**stackB;
	
	stackA = NULL;
	stackB = NULL;
	
	if (argc < 2)
	{
		perror("Error 1. Incorrect number of parameters\n");
		return(1);
	}
	parse(argc, argv);
	
	stackA = init(argc, argv);
	if (!(*stackA))
	{
		perror("Error 8. Failed to create list\n");
		free(stackA);
		return (8);
	}

	stackB = init(argc, argv);
	if (!(*stackA))
	{
		perror("Error 9. Failed to create list\n");
		free(stackA);
		return (9);
	}
	
	printf("PRUEBA 1\n");
	printf("Stack A\n");
	ver_lista(stackA);
	
	printf("Stack B\n");
	ver_lista(stackB);
	
	
	printf("PRUEBA 2\n");
	sa(stackA);
	printf("Stack A\n");
	ver_lista(stackA);
	
	printf("Stack B\n");
	ver_lista(stackB);


	printf("PRUEBA 3\n");
	ra(stackA);
	printf("Stack A\n");
	ver_lista(stackA);
	
	printf("Stack B\n");
	ver_lista(stackB);


	printf("PRUEBA 4\n");
	rra(stackA);
	printf("Stack A\n");
	ver_lista(stackA);
	
	printf("Stack B\n");
	ver_lista(stackB);
	
	
	printf("PRUEBA 5\n");
	pa(stackA, stackB);
	printf("Stack A\n");
	ver_lista(stackA);
	
	printf("Stack B\n");
	ver_lista(stackB);

/* 	printf("PRUEBA 3\n");
	to_bottom(stackA);
	ver_lista(stackA);

	printf("Prueba 4\n");
	to_top(stackA);
	ver_lista(stackA); */

	free(stackA);
	
	return (0);
}