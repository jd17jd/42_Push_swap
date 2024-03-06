/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:15:40 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/06 12:45:08 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

static int	num_occurences(int *nums, int num)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (nums[i])
	{
		if (nums[i] == num)
			res++;
		i++;
	}
	
	return (res);
}

static void	aux_parse(char *args[])
{
	int	i;
	int	elto;
	int	*enteros;

	i = 0;
	elto = 0;
	while (args[i])
		i++;
	enteros = ft_calloc(i, sizeof(int));
	if 	(!enteros)
	{
		perror("Error 2. Unable to allocate memory\n");
		exit(2);
	}
	i = 0;
	while (args[i])
	{
		elto = aux_atoi(args[i]);
		enteros[i] = elto; //pasar los enteros a un array de enteros
		i++;
	}
	i = 0;
	while (enteros[i]) //comprobacion duplicado
	{
		if (num_occurences(enteros, enteros[i]) > 1)
		{ 
			perror("Error 5. Duplicate values\n");
			exit(3);
		}
		i++;
	}
}

void	parse(int argc, char *argv[])
{
	char	**res;
	
	res = NULL;
	if (argc != 2)
		aux_parse(argv + 1);
	res = ft_split(argv[1], ' ');
	if (!res)
	{
		perror("Error 6. Impossible to create the array\n");
		exit(5);
	}
	if (!res[0])
	{
		perror("Error 7. 2nd value is NULL\n");
		exit(6);
	}
	aux_parse(res);
}