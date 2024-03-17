/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:15:40 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/16 20:29:31 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

int	number_arguments(int argc, char *argv[])
{
	int res;
	char **aux;
	//Para cuando ./push_swap 1 2 3 4 5 6
	if (argc != 2)
		return (argc - 1);

	//Para cuando es ./push_swap "1 2 3 4 5 6"
	res = 0;
	aux = ft_split(argv[1], ' ');
	while(aux[res])
		res++;
	return(res);
}


static int	num_occurences(int *nums, int num, int elto)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < elto)
	{
		if (nums[i] == num)
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

	enteros = ft_calloc(num_args, sizeof(int));
	if 	(!enteros)
	{
		perror("Error 2. Unable to allocate memory\n");
		exit(2);
	}
	i = 0;
	elto = 0;
	while (args[i])
	{
		elto = aux_atoi(args[i]);
		enteros[i] = elto; //pasar los enteros a un array de enteros
		i++;
	}
	elto = i;
	i = 0;
	while (i < elto) //comprobacion duplicado
	{
		if (num_occurences(enteros, enteros[i], elto) > 1)
		{
			perror("Error 5. Duplicate values\n");
			exit(3);
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
		perror("Error 6. Impossible to create the array\n");
		exit(5);
	}
	if (!aux[0])
	{
		perror("Error 7. 2nd value is NULL\n");
		exit(6);
	}
	res = aux_parse(aux, num_args);
	return (res);
}