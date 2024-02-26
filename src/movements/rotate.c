/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:03 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/26 20:38:06 by jvivas-g         ###   ########.fr       */
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

void    rotate(t_node **stack)
{
    if (!*stack)
        return ;

    // 1 - 2 - 3 - 4 - 5

    t_node *node = *stack;
    

}

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
