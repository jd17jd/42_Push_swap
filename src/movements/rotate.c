/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/27 22:54:20 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

//ROTATE

/*
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
/*
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last -> next = new;
	}
}
*/

/* t_stack_node	*find_last(t_stack_node *stack) //Define a function that returns the pointer to the last node
{
	if (!stack)
		return (NULL);
	while (stack->next) //Loop until the end of the stack is reached
		stack = stack->next;
	return (stack);
} */

void    rotate(t_node **stack)
{
	t_node *node = *stack;

    if (!*stack)
        return ;

	*stack = (*stack)->next;


/*     last_node = find_last(*stack); 
	last_node->next = *stack; //Assign to the last node, its `next` attribute as the top node, effectively setting the current top node as the last node
	*stack = (*stack)->next; //Assign to the pointer of the top node, the node after it (second from the top)
	(*stack)->prev = NULL; //Complete setting the current top node by detaching it from its previous top node
	last_node->next->prev = last_node; //Reconnect the second node's prev pointer to point to what was previously the last node in the stack
	last_node->next->next = NULL;  */
}

/*
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst -> next;
	return (lst);
}
*/

//ra
void    ra(t_node **a)
{
    rotate(a);
    printf("ra\n");
}

//rb
void    rb(t_node **b)
{
    rotate(b);
    printf("rb\n");
}

//rr
void    rr(t_node **a, t_node **b)
{
    rotate(a);
    rotate(b);
    printf("rr\n");
}
