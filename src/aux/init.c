/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:27:21 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/06 13:07:06 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

t_node    **init(int argc, char *argv[])
{
	int		i;
	t_node	**res;

	i = 1;
	res = NULL;
	res = ft_calloc(argc, sizeof(t_node *));
	while(argv[i])
	{
		t_node *node = node_new(i - 1, aux_atoi(argv[i]));
		if (node)
			node_add_back(res, node);
		i++;
	}
	return (res);
}

void	ver_lista(t_node **start)
{
	int		i;
	t_node	*actual;
	t_node	*next_node;

	i = 0;
	actual = start[0];
	while (actual)
	{
		printf("Node: %p, position: %d, content: %d\n", actual, i, actual->content);
		next_node = actual->next;
		actual = next_node;
		i++;
	}
}
