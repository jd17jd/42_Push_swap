/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verLista.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 03:05:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/28 03:07:46 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/ft_push_swap.h"

void	verLista(int argc, char *argv[]) {
	int i;
	t_list **start;

	i = 1;
	start = ft_calloc(argc, sizeof(t_list *));
	while(argv[i])
	{
		t_list *node = ft_lstnew(argv[i]);
		if (node)
			ft_lstadd_back(start, node);
		i++;
	}

	t_list *actual = start[0];
	while (actual)
	{
		printf("Node: %p, content: %s\n", actual, actual->content);
		actual = actual->next;
	}

	actual = start[0];
	while (actual)
	{
		t_list *next = actual->next;
		free(actual);
		actual = next;
	}
}