/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:15:40 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/05 12:29:03 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

/* Returns the total number of args we want to introduce in the first stack */
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

/* Returns the amount of times a number appears in the array */
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
		write(STDERR_FILENO, "Error\n", 6);
		exit(2);
	}
	while (args[i])
	{
		elto = aux_atoi(args[i]);
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
			write(STDERR_FILENO, "Error\n", 6);
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
	if (!aux || !*aux)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(6);
	}
	res = aux_parse(aux, num_args);
	free_array(aux);
	return (res);
}
