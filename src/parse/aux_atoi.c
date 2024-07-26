/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:23:05 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/07/27 01:15:31 by jvivas-g         ###   ########.fr       */
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

static int	convert_number(const char *str, int i, int sign)
{
	long long int	res;
	int				digit;

	res = 0;
	while (ft_isdigit(str[i]))
	{
		digit = str[i] - '0';
		if (res >= 0)
			res = res * 10 + digit;
		else
			res = res * 10 - digit;
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
		exit(4);
	}
	return (res * sign);
}

int	aux_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	while (str[i] && aux_space(str[i]))
		i++;
	sign = aux_sign(str[i]);
	i = aux_i(str[i], i);
	if (sign == -1)
		sign = -1;
	res = convert_number(str, i, sign);
	return (res);
}
