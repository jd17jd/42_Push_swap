/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:56:45 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/01/27 20:25:10 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	while (*lst)
	{
		aux = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = 0;
}
