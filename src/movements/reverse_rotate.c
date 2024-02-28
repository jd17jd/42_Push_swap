/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:01 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/28 11:48:58 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

//REVERSE ROTATION


/* void 	to_top(t_list **stack)
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
} */


// REV ROTATE - To check
void	rev_rotate(t_node **stack)
{
	t_node *last;
    if (!*stack || !(*stack)->next)
		return ;

    last = *stack;
    while (last->next)
        last = last->next;

    if (last->prev)
        last->prev->next = NULL;

    // Move the last node to the top of the stack.
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
}


//rra
void	rra(t_node **a)
{
	rotate(a);
	printf("rra\n");
}

//rrb
void	rrb(t_node **b)
{
    rotate(b);
    printf("rrb\n");
}

//rrr
void    rrr(t_node **a, t_node **b)
{
    rotate(a);
    rotate(b);
    printf("rrr\n");
}
