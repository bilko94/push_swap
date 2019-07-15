/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:22:43 by solivari          #+#    #+#             */
/*   Updated: 2019/07/15 16:47:56 by solivari         ###   ########.fr       */
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

int     main(int argc, char **argv)
{
    int		i;
	int		fv;
	t_body	*cursor;
	t_body	*stacka;
	t_body	*stackb;

	i = 2;
	fv = ft_atoi(argv[1]);
	stacka = setmaster(&stacka, fv);
	cursor = stacka;
	stackb = setmaster(&stackb, 0);
	if (argc > 1)
	{
		while (i < argc)
		{
			addnode(&stacka, ft_atoi(argv[i++]));
		}
		i = 1;
		while (i < argc)
		{
			addnode(&stackb, 0);
			i++;
		}
	}
	sa(&stacka);
	ft_putstr("stacka	stackb\n");
	while (cursor)
	{
		printf("%d	%d\n", cursor->value, stackb->value);
		// printf("master = %d	%d\n", stacka->master, stackb->master);
		cursor = cursor->next;
		stacka = stacka->next;
		stackb = stackb->next;
	}
	// printf("stacka = %d\n", stacka->value);
	return (0);
}

