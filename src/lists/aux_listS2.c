/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_listS2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:25:09 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/03/06 13:06:52 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ft_push_swap.h"

//ft_lstlast
t_node	*node_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

//ft_lstmap
t_node	*node_map(t_node *lst, t_node *(*f)(t_node *), void (*del)(t_node *))
{
    t_node	*res;
    t_node	*elto;
    t_node  *new_node;

    res = NULL;
    while (lst)
    {
        new_node = f(lst); // Apply the function f to the current node
        if (!new_node)
        {
            // Clean up and return NULL if memory allocation fails
            node_clear(&res);
            return (NULL);
        }
        elto = node_new(new_node->content, new_node->position);
        if (!elto)
        {
            // Clean up and return NULL if memory allocation fails
            node_clear(&res);
            del(new_node); // Free the memory allocated by the mapping function
            return (NULL);
        }
        node_add_back(&res, elto); // Add the mapped node to the result list
        lst = lst->next;
    }
    return (res);
} //To-check

//ft_lstnew
t_node	*node_new(int position, int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->position = position;
	node->prev = NULL;
	node->next = NULL;
	return (node);
} //OK

//ft_lstsize
int	node_size(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
} //OK
