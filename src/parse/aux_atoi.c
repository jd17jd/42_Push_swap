/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:23:05 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/06 13:15:14 by jvivas-g         ###   ########.fr       */
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

static int	aux_overflow(long int num)
{
    if (num > INT_MAX || num < INT_MIN)
        return (1);
    else
        return (0);
}

int aux_atoi(const char *str)
{
	int			i;
	long int	res;
	int			sign;
	int			digit;
	
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
		res = res * 10 + digit;
		if (aux_overflow(res) == 1)
		{
			perror("Error 3. Number out of range\n");
			exit(3);
		}
		i++;
	}
	
	if (digit == -1)
	{
		perror("Error 4. No number to convert\n");
		exit (4);
	}
	return (res * sign);
}