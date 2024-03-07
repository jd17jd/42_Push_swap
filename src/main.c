/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:05:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/07 00:46:15 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/ft_push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	**stackA;
	t_node	**stackB;
		
	if (argc < 2)
	{
		perror("Error 1. Incorrect number of parameters\n");
		return(1);
	}
	
	parse(argc, argv);

	stackA = NULL;
	stackB = NULL;

	(void) stackB;
	
	stackA = init(argc, argv);
	if (!(*stackA))
	{
		perror("Error 8. Failed to create list\n");
		free(stackA);
		return (8);
	}
	
	free(stackA);
	free(stackB);
	
	return (0);
}