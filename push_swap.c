/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:22:43 by solivari          #+#    #+#             */
/*   Updated: 2019/07/04 14:15:08 by solivari         ###   ########.fr       */
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

void	addnode(t_body **stacka, int value)
{
	t_body	*node;
	t_body	*cursor;

	cursor = (*stacka);
	node = create_node(value);
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
}

t_body	*setmaster(t_body **stacka)
{
	(*stacka) = create_node(0);
	(*stacka)->master = 1;
	return (*stacka);
}

int     main(int argc, char **argv)
{
    int		i;
	t_body	*cursor;
	t_body	*stacka;
	t_body	*stackb;

	i = 1;
	stacka = setmaster(&stacka);
	cursor = stacka;
	if (argc > 1)
	{
		while (i < argc)
		{
			addnode(&stacka, ft_atoi(argv[i++]));
		}
	}
	while (cursor)
	{
		printf("head value = %d\n", cursor->value);
		cursor = cursor->next;
	}
	printf("stacka = %d\n", stacka->value);
	return (0);
}

