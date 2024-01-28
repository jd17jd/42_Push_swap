/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:05:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/28 03:03:57 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/ft_push_swap.h"

int	main(int argc, char *argv[])
{
	int i;
	t_list **start;
	
	if (argc < 2)
	{
		perror("Incorrect number of parameters\n");
		return (1);
	}

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
	
	return (0);
}