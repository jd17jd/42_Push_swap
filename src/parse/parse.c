/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:15:40 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/19 13:45:17 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

int	number_arguments(int argc, char *argv[])
{
	int		res;
	char	**aux;

	if (argc != 2) //Para cuando ./push_swap 1 2 3 4 5 6
		return (argc - 1);
	res = 0; //Para cuando es ./push_swap "1 2 3 4 5 6"
	aux = ft_split(argv[1], ' ');
	while(aux[res])
		res++;
	free_array(aux);
	return(res);
} //OK

static int	num_occurences(int *array, int num, int size)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < size)
	{
		if (array[i] == num)
			res++;
		i++;
	}
	return (res);
}

static int 	*aux_parse(char *args[], int num_args)
{
	int	i;
	int	elto;
	int	*enteros;

	i = 0;
	elto = 0;
	enteros = (int *)ft_calloc(num_args, sizeof(int));
	if (!enteros)
	{
		perror("Error\n"); //Error 2. Unable to allocate memory
		exit(2);
	}
	while (args[i])
	{
		elto = aux_atoi(args[i]);
		enteros[i] = elto; //pasar los enteros a un array de enteros
		i++;
	}
	i = 0;
	while (i < num_args) //comprobacion duplicado
	{
		if (num_occurences(enteros, enteros[i], num_args) > 1)
		{
			perror("Error\n"); //Error 5. Duplicate values
			exit(5);
		}
		i++;
	}
	return (enteros);
}

int	*parse(int argc, char *argv[])
{
	int		num_args;
	int		*res;
	char	**aux;
	
	num_args = number_arguments(argc, argv);
	if (argc != 2)
		return (aux_parse(argv + 1, num_args));
	aux = ft_split(argv[1], ' ');
	if (!aux)
	{
		perror("Error\n"); //Error 6. Impossible to create the array
		exit(6);
	}
	if (!*aux)
	{
		perror("Error\n"); //Error 7. 2nd value is NULL
		exit(7);
	}
	res = aux_parse(aux, num_args);
	free_array(aux);
	return (res);
}