/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:05:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/18 16:23:12 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/ft_push_swap.h"

int	main(int argc, char *argv[])
{
	int		*aux;
	t_node	**stackA;
	t_node	**stackB;
		
	if (argc < 2)
	{
		perror("Error 1. Incorrect number of parameters\n");
		return(1);
	}

	aux = NULL;
	stackA = NULL;
	stackB = NULL;

	aux = parse(argc, argv);
	
	stackA = init(argc, argv, aux);
	
	stackB = ft_calloc(1, sizeof(t_node *));
	node_add_back(stackB, NULL);
	if (!stackA || !stackB)
	{
		perror("Error 8. Failed to create list\n");
		return (8);
	}
	ver_lista(stackA);
	printf("\n");
	order_stack(stackA, stackB);
	printf("\n");
	ver_lista(stackA);
	// pruebas_movements(stackA, stackB);
	//pruebas_algorithm(stackA, stackB);
	
	free(stackA);
	free(stackB);
	
	return (0);
}