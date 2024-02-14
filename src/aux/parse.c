/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:15:40 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/14 23:31:30 by jvivas-g         ###   ########.fr       */
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
	//comprobaciom num y en rango
	while (args[i])
		i++;
	enteros = ft_calloc(i, sizeof(int));
	i = 0;
	while (args[i])
	{
		elto = ft_atoi(args[i]);
		printf("%s\n", args[i]);
		printf("%d\n", elto);
		if (elto == -1)
		{ 
			perror("Error 1\n");
			exit(2);
		}
		//pasar los enteros a un array de enteros
		enteros[i] = elto;
		i++;
	}
	//comprobacion duplicado
	i = 0;
	while (enteros[i])
	{
		if (num_occurences(enteros, enteros[i]) > 1)
		{ 
			perror("Error 2\n");
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
	aux_parse(res);
}