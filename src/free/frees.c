/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:23:50 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/19 23:53:06 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_stack(t_node **stack)
{
	t_node	*aux;
	t_node	*aux2;

	aux = *stack;
	while (aux)
	{
		aux2 = aux;
		aux = aux->next;
		free(aux2);
	}
	free(stack);
}

