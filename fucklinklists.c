/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucklinklists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:42:56 by solivari          #+#    #+#             */
/*   Updated: 2019/08/30 14:05:24 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		set_index(t_body **stacka)
{
	int i;
	int j;
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

void printndx(t_body *stk)
{
   while (stk)
   {
       printf("group: %d. Index: %d\n", stk->gp, stk->dx);
       stk = stk->next;
   }
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

t_body	*setmaster(t_body **stack, int	fv)
{
	(*stack) = create_node(fv);
	(*stack)->master = 1;
	return (*stack);
}

void	vall(t_body *ta, t_body *tb)
{
	ft_putstr("\033[22;32m");
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
	ft_putstr("\033[22;32m");
}
