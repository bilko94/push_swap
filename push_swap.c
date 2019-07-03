/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:22:43 by solivari          #+#    #+#             */
/*   Updated: 2019/07/03 17:28:41 by solivari         ###   ########.fr       */
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

	node = create_node(value);
	(*stacka)->next = node;
}

void	setmaster(t_body *stacka)
{
	t_body	*node;
	node = create_node(0);
	node->master = 1;
}

int     main(int argc, char **argv)
{
    int		i;
	t_body	*stacka;
	t_body	*stackb;

	i = 1;
	setmaster(stacka);
	if (argc > 1)
	{
		while (i < argc)
		{
			addnode(&stacka, ft_atoi(argv[i++]));
		}
	}
	while (stacka->next != NULL)
	{
		printf("%d\n", stacka->value);
		stacka = stacka->next;
	}
	return (0);
}

