/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:27:59 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/08 22:28:04 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/ft_push_swap.h"


//ra --> swap A

//rb --> swap B

//ss --> both


void	swap(t_list	**stack)
{
	void	*temp_content;

	temp_content = stack[0]->content;
	stack[0]->content = stack[0]->next->content;
	stack[0]->next->content = temp_content;
}

void	to_bottom(t_list **stack)
{
	t_list	*node;
	t_list	*last;

	node = *stack; // Access the first node of the linked list
	printf("Nodo inicial: %d\n", ft_atoi(node->content));
	if (!node) // If the list is empty, there's nothing to do
		return ;
	last = ft_lstlast(node); // Find the last node of the list
	printf("Nodo final: %d\n", ft_atoi(last->content));
	ft_lstadd_back(stack, node); // Add the first node to the end of the list
	*stack = (*stack)->next; // Update the head of the list to point to the second node
	
	free(node);
	free(last);

	node = *stack;
	printf("Nuevo nodo inicial: %d\n", ft_atoi(node->content));
	last = ft_lstlast(node);
	printf("Nuevo nodo final: %d\n", ft_atoi(last->content));

	exit(1);
}