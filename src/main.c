/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:05:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/06 13:18:34 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/ft_push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	**stackA;
	t_node	**stackB;
	
	stackA = NULL;
	stackB = NULL;
	(void) stackA;
	(void) stackB;
	
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
	
	printf("Prueba 1\n");
	ver_lista(stackA);
	
	printf("Prueba 2\n");
	sa(stackA);
	ver_lista(stackA);

/* 	printf("Prueba 3\n");
	to_bottom(stackA);
	ver_lista(stackA);

	printf("Prueba 4\n");
	to_top(stackA);
	ver_lista(stackA); */

	free(stackA);
	
	return (0);
}