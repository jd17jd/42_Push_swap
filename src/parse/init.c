/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:27:21 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/21 13:46:07 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

static int *bubble_sort(int *array, int size)
{
    int i;
    int j;
    int aux;
	int *res;

	res = ft_calloc(size, sizeof(int));
	if (!res) //Check error number
	{
		fprintf(stderr, "Error\n"); //Error 9. Unable to allocate memory
		exit(9);
	}
    i = 0;
	while (i < size)
	{
		res[i] = array[i];
		i++;
	}
	i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (res[j] > res[j + 1])
            {
                aux = res[j];
                res[j] = res[j + 1];
                res[j + 1] = aux;
            }
            j++;
        }
        i++;
    }
	return (res);
}

static void order_array(int *not_ordered_array, int size)
{
	int i;
	int j;
	int *ordered_array;
	
	i = 0;
	ordered_array = bubble_sort(not_ordered_array, size);
	while (i < size)
	{
		j = 0;
		while(j < size)
		{
			if (not_ordered_array[i] == ordered_array[j])
			{
				not_ordered_array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static void	init_a(t_node **stackA, int argc, char *argv[], int *aux)
{
	int		i;
	int		num_args;
	t_node	*node;
	char	**aux2;

	i = 1;
	num_args = number_arguments(argc, argv);
	order_array(aux, num_args);
	aux2 = ft_split(argv[1], ' ');
	while(i <= num_args)
	{
		if (argc != 2)
		{
			//printf("Prueba 5\n");
			node = node_new(aux[i - 1], aux_atoi(argv[i]));
			if (node)
				node_add_back(stackA, node);
		}
		else
		{
			//printf("Prueba 6\n");
			node = node_new(aux[i - 1], aux_atoi(aux2[i - 1]));
			if (node)
				node_add_back(stackA, node);
		}
		i++;
	}
	//free_array(aux2);
	free(aux);
}

void	init(int argc, char *argv[], int *aux, t_node **stackA, t_node **stackB)
{
	if (!stackA || !stackB)
	{
		fprintf(stderr, "Error\n"); //Error 8. Unable to allocate memory
		exit(8);
	}
	*stackA = NULL;
	*stackB = NULL;
	init_a(stackA, argc, argv, aux);
}


void	ver_lista(t_node **start)
{
	int		i;
	t_node	*actual;
	t_node	*next_node;

	if (!start || !*start)
		return ;

	i = 0;
	actual = start[0];
	while (actual)
	{
		printf("Node: %p, position: %d, content: %d\n", actual, actual->position, actual->content);
		next_node = actual->next;
		actual = next_node;
		i++;
	}
}
