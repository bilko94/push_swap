/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucklinklists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:42:56 by solivari          #+#    #+#             */
/*   Updated: 2019/07/18 13:57:50 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_body	*create_node(int value)
{
	t_body	*node;

	if (!(node = (t_body *)malloc(sizeof(t_body))))
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	node->master = 0;
	return (node);
}

void	addnode(t_body **stack, int value)
{
	t_body	*node;
	t_body	*cursor;

	cursor = (*stack);
	node = create_node(value);
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
}

t_body	*setmaster(t_body **stack, int	fv)
{
	(*stack) = create_node(fv);
	(*stack)->master = 1;
	return (*stack);
}

void    printstacks(t_body **stacka, t_body **stackb)
{
    t_body	*cursora;
    t_body  *cursorb;
    
    cursora = (*stacka);
    cursorb = (*stackb);
    while (cursora || cursorb)
    {
        if (cursora != NULL && cursorb != NULL)
        { 
           printf("%d	%d\n", cursora->value, cursorb->value);
           cursora = cursora->next;
           cursorb = cursorb->next;
        }
	   	else if (cursorb == NULL && cursora != NULL)
	    {
            printf("%d	-\n", cursora->value);
	   	    cursora = cursora->next;
        }
        else if (cursora == NULL && cursorb != NULL)
        {
            printf("-	%d\n", cursorb->value);
            cursorb = cursorb->next;
        }
	}
}