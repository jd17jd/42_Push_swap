/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lista_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 03:05:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/10 13:16:11 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

void delete_element(t_list **head, void *ptr)
{
    t_list	*current;
    t_list	*prev;

	current = *head;
	prev = NULL;
	
    // Buscar el elemento a eliminar
    while (current && current->content != ptr) {
        prev = current;
        current = current->next;
    }

    // Si el elemento no se encuentra en la lista
    if (!current) {
        printf("El elemento no se encuentra en la lista.\n");
        return;
    }

    // Si el elemento está al principio de la lista
    if (!prev)
        *head = current->next;
	else
        prev->next = current->next;

    // Liberar la memoria del nodo
    free(current);
}


t_list	**crear_lista(int argc, char *argv[])
{
	int 	i;
	t_list	**res;
	
	i = 1;
	res = NULL;
	res = ft_calloc(argc, sizeof(t_list *));
	while(argv[i])
	{
		t_list *node = ft_lstnew(argv[i]);
		if (node)
			ft_lstadd_back(res, node);
		i++;
	}

	return (res);
}

void	ver_lista(t_list **start) {
	int		i;
	t_list	*actual;
	t_list	*next_node;

	i = 0;
	actual = start[0];
	while (actual)
	{
		printf("Node: %p, position: %d, content: %s\n", actual, i, (char *)actual->content);
		next_node = actual->next;
		actual = next_node;
		i++;
	}
}