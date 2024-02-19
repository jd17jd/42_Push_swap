/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:15:40 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/19 22:04:25 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

static int	aux_space(char c)
{
	return (
		c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r'
	);
}

static int	aux_sign(char str)
{
	if (str == '-')
		return (-1);
	return (1);
}


static int	aux_i (char c, int i)
{
	if (c == '-' || c == '+')
        return(++i);
	return (i);
}


static int aux_atoi(const char *str)
{
	int	i;
	int res;
	int sign;
	int digit;
	
	i = 0;
	res = 0;
	sign = 1;
	digit = -1;
	while(str[i] && aux_space(str[i]))
		i++;
	sign = aux_sign(str[i]);
	i = aux_i(str[i], i);
	while(ft_isdigit(str[i])) //Conversion de digitos a entero
	{
		digit = str[i] - '0';
		if ((INT_MAX - digit) / 10 < res)
		{ //Revisar logica de esto
			perror("Error 3. Number out of range\n");
			exit(3);
		}
		res *= 10 + digit;
		i++;
	}
	if (digit == -1)
	{
		perror("Error 4. No number to convert\n");
		exit (4);
	}
	
	return (res * sign);
}


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
		perror("Error 5. Impossible to create the array\n");
		exit(5);
	}
	if (res[0] == NULL)
	{
		perror("Error 6. 2nd value is NULL\n");
		exit(6);
	}
	aux_parse(res);
}