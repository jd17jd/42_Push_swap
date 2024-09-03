/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_strcpy_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:45:33 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/08/30 11:55:17 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

/* Copia un array de enteros */
int	*aux_strcpy_int(const int *original_array, int size)
{
	int	*new_array;
	int	j;

	new_array = (int *)malloc(size * sizeof(int));
	if (!new_array)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
	j = 0;
	while (j < size)
	{
		new_array[j] = original_array[j];
		j++;
	}
	return (new_array);
}
