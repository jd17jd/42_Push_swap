/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:05:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/10 13:17:17 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/ft_push_swap.h"

int	main(int argc, char *argv[])
{
	t_list **stackA;
	t_list **stackB;

	(void) stackB;
	if (argc < 2)
	{
		perror("Incorrect number of parameters\n");
		return (1);
	}

	stackA = crear_lista(argc, argv);
	if (!(*stackA))
	{
		perror("Failed to create list\n");
		free(stackA);
		return (1);
	}
	
	printf("Prueba 1\n");
	ver_lista(stackA);
	
	printf("Prueba 2\n");
	swap(stackA);
	ver_lista(stackA);

	printf("Prueba 3\n");
	to_bottom(stackA);
	ver_lista(stackA);

	printf("Prueba 4\n");
	to_top(stackA);
	ver_lista(stackA);

	free(stackA);
	
	return (0);
}