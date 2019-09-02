/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucklinklists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:42:56 by solivari          #+#    #+#             */
/*   Updated: 2019/09/02 16:41:11 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		set_index(t_body **stacka)
{
	int		i;
	int		j;
	t_body	*t;
	t_body	*t1;

	i = 0;
	j = ft_list_size(*stacka);
	t = (*stacka)->next;
	while (i < j)
	{
		t1 = (*stacka)->next;
		t = t1;
		while (t->dx)
			t = t->next;
		while (t1)
		{
			if ((t1->value < t->value) && !(t1->dx))
				t = t1;
			t1 = t1->next;
		}
		if (!(t->dx))
			t->dx = ++i;
	}
	return (i);
}

t_body	*create_node(int value)
{
	t_body	*node;

	if (!(node = (t_body *)malloc(sizeof(t_body))))
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	node->dx = 0;
	node->gp = 0;
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
	node->prev = cursor;
}

t_body	*setmaster(t_body **stack, int fv)
{
	(*stack) = create_node(fv);
	(*stack)->master = 1;
	return (*stack);
}
