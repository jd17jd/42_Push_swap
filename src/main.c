/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:05:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/20 00:33:16 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/ft_push_swap.h"

int	main(int argc, char *argv[])
{
	int		*aux;
	t_node	**stackA;
	t_node	**stackB;
		
	if (argc < 2) //Error 1. Nº argumentos incorrectos
	{
		perror("Error\n");
		return(1);
	}
	
	aux = NULL;
	stackA = (t_node **)ft_calloc(1, sizeof(t_node *));
	stackB = (t_node **)ft_calloc(1, sizeof(t_node *));
	
	aux = parse(argc, argv);
	init(argc, argv, aux, stackA, stackB);
	
	// ver_lista(stackA);
	// printf("\n");
	order_stack(stackA, stackB);
	// printf("\n");
	// ver_lista(stackA);
	// printf("\n");
	
	//pruebas_movements(stackA, stackB);
	//pruebas_algorithm(stackA, stackB);
	
	free_stack(stackA);
	free_stack(stackB);
	
	return (0);
}
