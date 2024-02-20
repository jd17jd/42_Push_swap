/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:59:15 by jvivas-g          #+#    #+#             */
/*   Updated: 2024/02/20 21:50:12 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <sys/fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../lib/inc/libft.h"

typedef struct s_node_linked_list // 's_' for struct
{
	int							content;
	int							position;
	
	struct s_node_linked_list	*prev;
	struct s_node_linked_list	*next;
	
}	t_stack; // 't_' for type

/* PUSH SWAP AUX */
void    delete_element(t_list **head, void *ptr);
t_list	**crear_lista(int argc, char *argv[]);
void	ver_lista(t_list **start);

int 	aux_atoi(const char *str);
void	parse(int argc, char *argv[]);

/* MOVEMENTS */
void	swap(t_stack **stack);
void	to_bottom(t_list **stack);
void 	to_top(t_list **stack);


#endif