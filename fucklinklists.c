/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucklinklists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:42:56 by solivari          #+#    #+#             */
/*   Updated: 2019/08/15 15:16:46 by solivari         ###   ########.fr       */
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

void	vall(t_body *ta, t_body *tb)
{
	ta = ta->next;
	tb = tb->next;
	while (ta || tb)
	{
		if (ta != NULL && tb != NULL)
		{
			ft_putstr(ft_itoa(ta->value));
			ft_putstr("\t\t");
			ft_putendl(ft_itoa(tb->value));
			ta = ta->next;
			tb = tb->next;
		}
		else if (ta != NULL && tb == NULL)
		{
			ft_putstr(ft_itoa(ta->value));
			ft_putstr("\t\t");
			ft_putendl("-");
			ta = ta->next;
		}
		else if (ta == NULL && tb != NULL)
		{
			ft_putstr("-");
			ft_putstr("\t\t");
			ft_putendl(ft_itoa(tb->value));
			tb = tb->next;
		}
	}
}
