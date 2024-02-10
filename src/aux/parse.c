/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:15:40 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/10 14:02:37 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

static void	aux_parse(char **args)
{
	//Hacer esta funcion para cuando el programa solo reciba un parametro
}

static void	parse(int argc, char *argv[])
{
	char	**res;
	int		i;
	
	res = NULL;
	i = 2;
	if (argc < 2)
	{
		perror("Incorrect number of parameters\n");
		exit(1);
	}
	if (argc == 2)
	{
		res = ft_split(argv[1], ' ');
		aux_parse(res);
	}
	else {
			while (argv[i])
			{
				//Comprobar atoi cuando me de mal
				i++;
			}
	}
}