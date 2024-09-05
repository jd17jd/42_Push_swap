/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_strcpy_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:45:33 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/09/05 12:21:41 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

/* Copies an array of integers */
int	*aux_strcpy_int(const int *original_array, int size)
{
	int	*new_array;
	int	j;

	new_array = (int *)ft_calloc(size, sizeof(int));
	if (!new_array)
	{
		fprintf(stderr, "Error8\n");
		exit(8);
	}
	j = 0;
	while (j < size)
	{
		new_array[j] = original_array[j];
		j++;
	}
	return (new_array);
}
