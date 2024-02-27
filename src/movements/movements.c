/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:27:59 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/27 22:37:36 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"


void	to_swap(t_list	**stack)
{
	void	*temp_content;

	temp_content = stack[0]->content;
	stack[0]->content = stack[0]->next->content;
	stack[0]->next->content = temp_content;
}

void	to_bottom(t_list **stack)
{
	t_list	*node;

	node = *stack;
	if (!node)
		return ;
		
	*stack = (*stack)->next;
	
	ft_lstadd_back(stack, ft_lstnew(ft_strdup(node->content)));
    free(node);
}

void 	to_top(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	last = ft_lstlast(*stack);
	if (!last)
		return ;

	if (*stack == last) { // Si solo hay un nodo en la lista
        ft_lstdelone(last, &free); // Eliminar el último nodo
        *stack = NULL; // Establecer el puntero a la lista como NULL
        return;
    }

	ft_lstadd_front(stack, ft_lstnew(ft_strdup(last->content)));

	second_last = *stack;
    while (second_last->next != last) {
        second_last = second_last->next;
    }

    second_last->next = NULL; // Establecer el enlace del segundo último nodo a NULL
    ft_lstdelone(last, &free); // Eliminar el último nodo
}

