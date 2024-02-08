/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:27:59 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/03 12:28:59 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/ft_push_swap.h"


//ra --> swap A

//rb --> swap B

//ss --> both


void	swap(t_list	**stack)
{
	void	*temp_content;

	/*
	printf("%c\n", *(char *)(stack[0]->content));
	printf("%c\n", *(char *)(stack[0]->next->content));
	*/
	temp_content = stack[0]->content;
	stack[0]->content = stack[0]->next->content;
	stack[0]->next->content = temp_content;
}

void	to_bottom(t_list **stack)
{
	t_list	*node;
	node = stack[0];
	ft_lstadd_back(stack, node);
	*stack = (*stack)->next;
	ft_lstdelone(stack[0], free);
}