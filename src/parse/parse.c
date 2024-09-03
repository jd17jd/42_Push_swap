/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:15:40 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/03 22:33:34 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

/* Deevuelve el nº total de args que buscamos introducir en la primera pila */
int	number_arguments(int argc, char *argv[])
{
	int		res;
	char	**aux;

	if (argc != 2)
		return (argc - 1);
	res = 0;
	aux = ft_split(argv[1], ' ');
	while (aux[res])
		res++;
	free_array(aux);
	return (res);
}

/* Devuelve el numero de veces que aparece un numero en un array */
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

static int	*allocate_and_parse(char *args[], int num_args)
{
	int	i;
	int	elto;
	int	*enteros;

	i = 0;
	elto = 0;
	enteros = (int *)ft_calloc(num_args, sizeof(int));
	if (!enteros)
	{
		fprintf(stderr, "Error\n");
		exit(2);
	}
	while (args[i])
	{
		elto = ft_atoi(args[i]);
		enteros[i] = elto;
		i++;
	}
	return (enteros);
}

static int	*aux_parse(char *args[], int num_args)
{
	int	i;
	int	*enteros;

	i = 0;
	enteros = allocate_and_parse(args, num_args);
	while (i < num_args)
	{
		if (num_occurences(enteros, enteros[i], num_args) > 1)
		{
			fprintf(stderr, "Error\n");
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
		return (res = aux_parse(argv + 1, num_args));
	aux = ft_split(argv[1], ' ');
	if (!aux)
	{
		fprintf(stderr, "Error\n");
		exit(6);
	}
	if (!*aux)
	{
		fprintf(stderr, "Error\n");
		exit(7);
	}
	res = aux_parse(aux, num_args);
	free_array(aux);
	return (res);
}
