/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:22:20 by solivari          #+#    #+#             */
/*   Updated: 2019/07/22 16:18:34 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_body **stacka)
{
	t_body  *cursorend;
	t_body  *firsta;
	t_body	*seconda;

	firsta = (*stacka)->next;
	seconda = firsta->next;
	cursorend = (*stacka);
	while (cursorend->next)
		cursorend = cursorend->next;
	if (seconda)
	{
		cursorend->next = firsta;
		(*stacka)->next = seconda;
		firsta->next = NULL;
	}
}

void	rb(t_body **stackb)
{
	t_body  *cursorend;
	t_body	*secondb;
	t_body  *firstb;

	firstb = (*stackb)->next;
	secondb = firstb->next;
	cursorend = (*stackb);
	while (cursorend->next)
		cursorend = cursorend->next;
	if (secondb)
	{
		cursorend->next = firstb;
		(*stackb)->next = secondb;	
		firstb->next = NULL;
	}
}

void	rr(t_body **stacka, t_body **stackb)
{
	ra(stacka);
	rb(stackb);
}

void	rra(t_body **stacka)
{
	t_body  *cursorend;
	t_body  *secondlast;
	t_body  *firsta;
	t_body	*seconda;

	if (!((*stacka)->next) || !((*stacka)->next->next))
		return ;
	firsta = (*stacka)->next;
	seconda = firsta->next;
	cursorend = (*stacka);
	secondlast = (*stacka);
	while (cursorend->next)
		cursorend = cursorend->next;
	while (secondlast->next->next)
		secondlast = secondlast->next;
	if (firsta && seconda)
	{
		cursorend->next = firsta;
		(*stacka)->next = cursorend;
		secondlast->next = NULL;
	}
}

void    rrb(t_body **stackb)
{
	t_body  *cursorend;
	t_body  *secondlast;
	t_body  *firstb;
	t_body	*secondb;

	if (!((*stackb)->next) || !((*stackb)->next->next))
		return ;
	firstb = (*stackb)->next;
	secondb = firstb->next;
	cursorend = (*stackb);
	secondlast = (*stackb);
	while (cursorend->next)
		cursorend = cursorend->next;
	while (secondlast->next->next)
		secondlast = secondlast->next;
	if (firstb && secondb)
	{
		cursorend->next = firstb;
		(*stackb)->next = cursorend;
		secondlast->next = NULL;
	}
}

void    rrr(t_body **stacka, t_body **stackb)
{
	rra(stacka);
	rrb(stackb);
}
