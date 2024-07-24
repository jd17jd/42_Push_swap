/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:23:05 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/21 14:13:25 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

static int	aux_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
}

static int	aux_sign(char str)
{
	if (str == '-')
		return (-1);
	return (1);
}

static int	aux_i(char c, int i)
{
	if (c == '-' || c == '+')
		return (++i);
	return (i);
}

int	aux_atoi(const char *str)
{
	int				i;
	long long int	res;
	int				sign;
	int				digit;

	i = 0;
	res = 0;
	sign = 1;
	digit = -1;
	while (str[i] && aux_space(str[i]))
		i++;
	sign = aux_sign(str[i]);
	i = aux_i(str[i], i);
	if (sign == -1)
		res *= sign;
	while (ft_isdigit(str[i]))
	{
		digit = str[i] - '0';
		if (res >= 0)
			res = res * 10 + digit;
		if (res < 0)
			res = res * 10 - digit;
		if (sign == -1)
		{
			res *= sign;
			sign = 0;
		}
		if (res > 2147483647 || res < -2147483648)
		{
			fprintf(stderr, "Error\n");
			exit(3);
		}
		i++;
	}
	if ((!str[i] && digit == -1) || (str[i] && !ft_isdigit(str[i])))
	{
		fprintf(stderr, "Error\n");
		exit (4);
	}
	return (res);
}
