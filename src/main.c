/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:05:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/19 23:15:07 by jvivas-g         ###   ########.fr       */
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
	
	ver_lista(stackA);
	// printf("\n");
	order_stack(stackA, stackB);
	// printf("\n");
	ver_lista(stackA);
	// printf("\n");
	
	//pruebas_movements(stackA, stackB);
	//pruebas_algorithm(stackA, stackB);
	
	free_stack(stackA);
	free_stack(stackB);
	
	return (0);
}

/*
3 2 1 4 5

3 <-- current
2
1
4
5 <-- highest

rra =
5 3 2 1 4

5 <-- current <-- highest
3
2
1
4

pb =
3 2 1 4

3 <-- current
2
1
4  <-- highest
x
5 <-- current <-- highest

rra =
4 3 2 1

4 <-- current <-- highest
3 
2
1
x
5 <-- current <-- highest

pb =
3 2 1

3 <-- current <-- highest
2
1
x
4 <-- current 
5 <-- highest

ra =
2 1 3

2 <-- current 
1
3 <-- highest
x
4 <-- current
5 <-- highest

sa =
1 2 3

1 <-- current
2
3 <-- highest
x
4 <-- current
5 <-- highest

pa =
4 1 2 3

4 <-- current
1
2
3 <-- highest
x
5 <-- current <-- highest

pa =
4 1 2 3

5 <-- current <-- highest
4
1
2
3


*/