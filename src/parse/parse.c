/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:15:40 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/21 14:57:33 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

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

static int	*aux_parse(char *args[], int num_args)
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
		elto = aux_atoi(args[i]);
		enteros[i] = elto;
		i++;
	}
	i = 0;
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
