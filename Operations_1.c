/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:51:58 by solivari          #+#    #+#             */
/*   Updated: 2019/08/30 19:08:19 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_body **stacka)
{
	t_body	*firsta;
	t_body	*seconda;

	firsta = (*stacka)->next;
	seconda = firsta->next;
	if (seconda)
	{
		(*stacka)->next = seconda;
		firsta->next = seconda->next;
		seconda->next = firsta;
	}
}

void	sb(t_body **stackb)
{
	t_body	*firstb;
	t_body	*secondb;

	firstb = (*stackb)->next;
	secondb = firstb->next;
	if (secondb)
	{
		(*stackb)->next = secondb;
		firstb->next = secondb->next;
		secondb->next = firstb;
	}
}

void	ss(t_body **stacka, t_body **stackb)
{
	sa(&(*stacka));
	sb(&(*stackb));
}

void	pb(t_body **stacka, t_body **stackb)
{
	t_body	*firsta;
	t_body	*firstb;

	firsta = (*stacka)->next;
	firstb = (*stackb)->next;
	if (firsta)
	{
		(*stacka)->next = firsta->next;
		(*stackb)->next = firsta;
		firsta->next = firstb;
	}
	return ;
}

void	pa(t_body **stacka, t_body **stackb)
{
	t_body	*firsta;
	t_body	*firstb;

	firsta = (*stacka)->next;
	firstb = (*stackb)->next;
	if (firstb)
	{
		(*stackb)->next = firstb->next;
		(*stacka)->next = firstb;
		firstb->next = firsta;
	}
	return ;
}
