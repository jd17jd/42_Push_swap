/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:23:05 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/04 12:54:47 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

static int	aux_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
}

static int	convert_number(const char *str, int i, int sign)
{
	long long int	res;
	int				digit;

	res = 0;
	digit = 0;
	while (ft_isdigit(str[i]))
	{
		digit = str[i++] - '0';
		res = res * 10 + digit * sign;
		if (res > 2147483647 || res < -2147483648)
		{
			write(STDERR_FILENO, "Error\n", 6);
			exit(3);
		}
	}
	if (!ft_isdigit(str[i]) && str[i] != '\0')
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(4);
	}
	return (res);
}

int	aux_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] && aux_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(4);
	}
	return (convert_number(str, i, sign));
}
