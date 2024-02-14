/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:22:38 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/14 23:34:34 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include <stdio.h>

static int	aux_space(char c)
{
	return (
		c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r'
	);
}

static int aux_sign(char str)
{
	if (str == '-' || str == '+')
	{
		if (str == '-')
			return (-1);
	}
	return (1);
}
/**
 * Converts the the string pointed to by "str" to int.
 * @param str String to be converted
 * @return int result of the conversion, -1 if it's not a number
 * or exceeds range [INT_MIN, INT_MAX]
 * @warning Spaces at the beginning of string are ignored.
 * takes into consideration negative numbers, as well
*/
int ft_atoi(const char *str) {
    int i = 0;
    int res = 0;
    int sign = 1;
    int digit_seen = 0; // Indicador para verificar si al menos se ha visto un dígito

    // Manejo de espacios y signos
    while (str[i] && aux_space(str[i]))
        i++;
    sign = aux_sign(str[i]);
    if (str[i] == '-' || str[i] == '+')
        i++;

    // Conversión de dígitos a entero
    while (ft_isdigit(str[i])) {
        digit_seen = 1; // Se ha visto al menos un dígito
        int digit = str[i] - '0';

        // Verificar desbordamiento antes de la siguiente multiplicación
        if ((INT_MAX - digit) / 10 < res) {
            return (-1); // Desbordamiento
        }

        res = res * 10 + digit;
        i++;
    }

    // Si no se ha visto ningún dígito, devolver -1
    if (!digit_seen)
        return (-1);

    // Aplicar el signo y devolver el resultado
    return (res * sign);
}
