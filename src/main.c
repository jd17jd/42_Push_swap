/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:05:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/19 21:58:39 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/ft_push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	**stackA;
	t_stack	**stackB;
	
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
	return (0);
}